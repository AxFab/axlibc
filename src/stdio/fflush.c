#include <ax/file.h>
#include <string.h>
#include <fcntl.h>

// ---------------------------------------------------------------------------
int fill_cache (FILE* fp)
{
  size_t bread = read( fp->fd_, fp->buf_, fp->bsize_);

  if (bread != fp->bsize_) {
      if (bread == 0) {
        fp->oflags_ |= OF_EOF;
        return EOF;
      }

      fp->off_ += bread;
      // FIXME
      return 0;

  } else {
      fp->oflags_ |= OF_ERR;
      return EOF;
  }
}


// ---------------------------------------------------------------------------
int flush_cache (FILE* fp)
{
  // size_t written = 0;

  // while (written != fp->_bufidx) {
  //   size_t wrest = fp->_bufidx - written;
  //   size_t rest = write( fp->fd_, fp->buf_+ written, wrest);

  //   written += rest;
  //   fp->_position += rest;

  //   if (rest != wrest) {
  //     fp->oflags_ |= OF_ERR;
  //     fp->_bufidx -= written;
  //     memmove(fp->buf_, fp->buf_ + written, fp->_bufidx);
  //     return EOF;
  //   }
  // }

  // fp->_bufidx = 0;
  return 0;
}

// ---------------------------------------------------------------------------
int fflush (FILE* fp)
{
  int res = 0;

  if (fp != NULL) {
    flockfile (fp);
    res = flush_cache (fp);
    funlockfile (fp);
    return res;
  }

  fp = OFP_HEAD;
  while (fp != NULL) {
    if (fp->oflags_ &= (O_WRONLY | O_RDWR)) {
      flockfile (fp);
      res |= flush_cache (fp);
      funlockfile (fp);
    }

    fp = fp->next_;
  }

  return res;
}


void setbuf(FILE *stream, char *buf)
{

}
