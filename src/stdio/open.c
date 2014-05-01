#include <stdlib.h>
#include <stream.h>

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
    __seterrno(EBADF);
    return NULL;
  }

  if (oflags == 0) {
    __seterrno(EINVAL);
    return NULL;
  }

  fp = (FILE*)malloc (sizeof(FILE));
  if (!fp) {
    __seterrno(ENOMEM);
    return NULL;
  }

  if (mtx_init(&fp->_lock, MTX_RECURSIVE) != MTX_SUCESS) {
    __seterrno(ENOLCK);
    free(fp);
    return NULL;
  }

  fp->_fd = fd;
  fp->_oflags = oflags | _IOLBF;
  fp->_cache = (uint8_t*)malloc (BUFSIZ);
  fp->_bufsize = BUFSIZ;
  fp->_position = 0;
  fp->_bufidx = 0;
  fp->_ungetidx = 0;
  fp->_next = OFP_HEAD;
  OFP_HEAD = fp;

  /* If O_APPEND is set, we need to set cursor at the end */
  if (oflags & O_APPEND) {
	fp->_position = lseek(fd, (fpos_t)0, SEEK_END);
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
FILE *freopen(const char *restrict file, const char *restrict mode, FILE *restrict stream) 
{
  int oflags = stream->_oflags & ( _IONBF | _IOLBF | _IOFBF );
  if (file == NULL) {
    /* Change mode if incompatible */
  }

  flockfile(stream);

  /* flush buffers */
  if (stream->_oflags &= (O_WRONLY | O_RDWR)) {
    if (flush_cache (stream) == EOF) {
      funlockfile (stream);
      return NULL;
    }
  }

  if (file == NULL || stream->_path == NULL) {
    funlockfile (stream);
    return NULL;
  }
  
  close (stream->_fd);

  /* Re-add the flags we saved above */
  stream->_oflags |= oflags;
  stream->_bufidx = 0;
  stream->_bufend = 0;
  stream->_ungetidx = 0;
  
  stream->_fd = open(stream->_path, stream->_oflags, 0);
  if (stream->_fd == 0)
  {
    funlockfile( stream );
    return NULL;
  }
  
  funlockfile( stream );
  return stream;
}


