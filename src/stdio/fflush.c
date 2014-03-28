#include <prv/stream.h>

// ---------------------------------------------------------------------------
int fill_cache (FILE* stream)
{
  size_t bread = read( stream->_fd, stream->_cache, stream->_bufsize);

  if (bread != stream->_bufsize) {
      if (bread == 0) {
        stream->_oflags |= OF_EOF;
        return EOF;
      }

      stream->_position += bread;
      stream->_bufend = bread;
      stream->_bufidx = 0;
      return 0;
      
  } else {
      stream->_oflags |= OF_ERR;
      return EOF;
  }
}


// ---------------------------------------------------------------------------
int flush_cache (FILE* stream)
{
  size_t written = 0;

  while (written != stream->_bufidx) {
    size_t wrest = stream->_bufidx - written;
    size_t rest = write( stream->_fd, stream->_cache+ written, wrest);

    written += rest;
    stream->_position += rest;

    if (rest != wrest) {
      stream->_oflags |= OF_ERR;
      stream->_bufidx -= written;
      memmove(stream->_cache, stream->_cache + written, stream->_bufidx);
      return EOF;
    }
  }

  stream->_bufidx = 0;
  return 0;
}

// ---------------------------------------------------------------------------
int fflush (FILE* stream)
{
  int res = 0;

  if (stream != NULL) {
    flockfile (stream);
    res = flush_cache (stream);
    funlockfile (stream);
    return res;
  }

  stream = OFP_HEAD;
  while (stream != NULL) {
    if (stream->_oflags &= (O_WRONLY | O_RDWR)) {
      flockfile (stream);
      res |= flush_cache (stream);
      funlockfile (stream);
    }

    stream = stream->_next;
  }

  return res;
}



