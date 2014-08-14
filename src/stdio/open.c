#include <stdlib.h>
#include <ax/file.h>
#include <ax/mutex.h>
#include <errno.h>
#include <fcntl.h>

FILE* OFP_HEAD = NULL;
// ===========================================================================
/**
 * Allocate a new FILE structure form an open file descriptor
 *
 * @param fd                [in] File descritpor of this file
 * @param oflags            [in] Flags sended to the open function
 * @param rflags            [in] Flags !?
 *
 * @throw ENOMEM                    Not enough memory left
 * @throw EBADF                     Invalid file descriptor
 * @throw EINVAL                    The flags are invalid
 */
static FILE* _fvopen(int fd, int oflags, int rflags)
{
  FILE* fp;

  if (!fd) {
    errno = EBADF;
    return NULL;
  }

  if (oflags == 0) {
    errno = EINVAL;
    return NULL;
  }

  fp = (FILE*)malloc (sizeof(FILE));
  if (!fp) {
    errno = ENOMEM;
    return NULL;
  }

  if (mtx_init(&fp->lock_, MTX_RECURSIVE) != MTX_SUCESS) {
    errno = ENOLCK;
    free(fp);
    return NULL;
  }

  fp->fd_ = fd;
  fp->oflags_ = oflags | _IOLBF;
  fp->count_ = 0;
  fp->lbuf_ = EOF;
  fp->buf_ = (char*)malloc (BUFSIZ);
  fp->rpos_ = fp->wpos_ = fp->buf_;
  fp->rend_ = fp->wend_ = fp->buf_ + BUFSIZ;
  fp->off_ = 0;
  fp->bsize_ = BUFSIZ;
  fp->next_ = OFP_HEAD;
  fp->read_ = _dread;
  fp->write_ = _dwrite;
  OFP_HEAD = fp;

  /* If O_APPEND is set, we need to set cursor at the end */
  if (oflags & O_APPEND) {
	 fp->lpos_ = lseek(fd, (fpos_t)0, SEEK_END);
  }

  return fp;
}

// ---------------------------------------------------------------------------
/**
 * Parse the character base mode for opening file. and return binary mode
 *
 * @param mode              [in] A character string that define an opening mode
 *
 * @return                  An integer that contains opening flags, or zero if
 *                            mode is invalid
 *
 * The mode parameter must start by on of this sequence:
 *   r  Open the file for reading. The stream is positioned at the beginning
 *        of the file.
 *   r+ Open the file for reading and writing. The stream is positioned at the
 *        beginning of the file.
 *   w  Truncate file to zero length or create a new file for writing. The
 *        stream is positioned at the beginning of the file.
 *   w+ Open the file for reading and writing. The file is created if needed,
 *        or truncated. The stream is positioned at the beginning of the file.
 *   a  Open for appending (writing at the end). The file is created if it
 *        doesn't exist. The stream is positioned at the end of file.
 *   a+  Open for reading and appending (writing at the ent). The initial file
 *        position is at the beginning, but output is always append to teh end.
 *
 * The mode can be completed by this extensions:
 *   b   (mingw32) Try to optimize for binary file
 *   x   (glibc) Open the file exclusively (like O_EXEC)
 *   e   (glibc) Close the file on exec
 *   m   (glibc) Try to use mmap
 *   F   (uClibc) Open a a large file
 *
 * Note: on this implementation repeated or unknown extensions don't cause any
 *   errors and '+' is consider as and extensions rather than a mode suffix.
 */
static int _foflags (const char* mode)
{
  int oflags = 0;
  if (*mode == 'r') {
    oflags |= O_RDONLY;
  } else if (*mode == 'w') {
    oflags |= O_WRONLY | O_CREAT | O_TRUNC;
  } else if (*mode == 'a') {
    oflags |= O_WRONLY | O_CREAT | O_APPEND;
  } else {
    return 0;
  }

  ++mode;
  while (*mode != '\0' && *mode != ',') {
    switch (*mode) {
      case 'r':
      case 'w':
      case 'a':
        return 0;

      case '+':
        oflags &= ~(O_RDONLY | O_WRONLY);
        oflags |= O_RDWR;
        break;

      case 'b': oflags |= O_BINARY; break;
#ifdef __GNU
      case 'x': oflags |= O_EXCL; break;
      case 'e': oflags |= O_CLOEXEC; break;
      case 'm': oflags |= O_MEMORYMAP; break;
#endif
#ifdef __EXT
      case 'F': oflags |= O_LARGEFILE; break;
#endif
    }
    ++mode;
  }
  return oflags;
}

// ===========================================================================
/**
 * Open a file and create a new stream
 *
 * @param file              [in] The filename of the file to open, rooted or
 *                                 relative to PWD
 * @param mode              [in] A character string that define an opening mode
 *
 * @return                  A pointer on a FILE structure or NULL in case of
 *                            error
 *
 * @throw open              Throw all error from the function open
 * @throw _fdopen           Throw all error from the function _fdopen
 */
FILE* fopen (const char* restrict file, const char* restrict mode)
{
  int fd;
  int oflags;
  FILE* fp;

  /* Get openning flags */
  oflags = _foflags(mode);
  if (oflags == 0 || file == NULL) {
    return NULL;
  }

  /* Open file get file ID */
  fd = open(file, oflags, OF_RIGHTS);
  if (!fd) {
    return NULL;
  }

  fp = _fvopen(fd, oflags, oflags);
  if (fp == NULL) {
    close (fd);
  }

  return fp;
}


// ---------------------------------------------------------------------------
/**
 * Create a stream for a opened file
 */
FILE* fdopen(int fd, const char* mode)
{
  int oflags;

  /* Get openning flags */
  oflags = _foflags(mode);
  if (!oflags) {
    return NULL;
  }

  return _fvopen(fd, oflags, 0);
}

// ---------------------------------------------------------------------------
/**
 * Create a new stream base on another one
 */
// FILE *freopen(const char *restrict file, const char *restrict mode, FILE *restrict fp)
// {
//   int oflags = fp->oflags_ & ( _IONBF | _IOLBF | _IOFBF );
//   if (file == NULL) {
//     /* Change mode if incompatible */
//   }

//   flockfile(fp);

//   /* flush buffers */
//   if (fp->oflags_ &= (O_WRONLY | O_RDWR)) {
//     if (flush_cache (fp) == EOF) {
//       funlockfile (fp);
//       return NULL;
//     }
//   }

//   if (file == NULL || fp->path_ == NULL) {
//     funlockfile (fp);
//     return NULL;
//   }

//   close (fp->fd_);

//   /* Re-add the flags we saved above */
//   fp->oflags_ |= oflags;
//   fp->bufidx_ = 0;
//   fp->bufend_ = 0;
//   fp->ungetidx_ = 0;

//   fp->fd_ = open(fp->path_, fp->oflags_, 0);
//   if (fp->fd_ == 0)
//   {
//     funlockfile(fp);
//     return NULL;
//   }

//   funlockfile(fp);
//   return fp;
// }


