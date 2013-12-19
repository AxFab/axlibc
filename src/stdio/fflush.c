#include <prv/stream.h>

// ---------------------------------------------------------------------------
int fill_cache (FILE* stream)
{
  size_t bread;
  int res = read( stream->_fd, stream->_cache, stream->_bufsize, &bread);

  if (res) {
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
    size_t rest = stream->_bufidx - written;
    int res = write( stream->_fd, stream->_cache+ written, rest, &rest);

    written += rest;
    stream->_position += rest;

    if (res) {
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



