#include <errno.h>
#include <stdint.h>
#include <prv/stream.h>


int fgetpos (FILE* restrict stream, fpos_t* restrict pos)
{
  flockfile (stream);
  *pos = stream->_position + stream->_bufidx - stream->_ungetidx;
  funlockfile (stream);
  return 0;
}


int fseek (FILE* stream, long loffset, int whence)
{
  uint64_t offset = loffset;

  flockfile (stream);

  /* flush buffers */
  if (stream->_oflags &= (O_WRONLY | O_RDWR)) {
    if (fflush_unlocked (stream) == EOF) {
      funlockfile (stream);
      return EOF;
    }
  }

  stream->_oflags &= ~OF_EOF;
  if ( stream->_oflags & O_RDWR )
  {
    stream->_oflags &= ~( O_RDONLY | O_WRONLY );
  }

  if (whence == SEEK_CUR)
  {
      whence = SEEK_SET;
      offset += _ftell64 (stream);
  }

  stream->_position = lseek (stream->_fd, offset, whence);
  funlockfile (stream);
  return ( stream->_position == loffset ) ? 0 : EOF;
}


int fsetpos (FILE* stream, const fpos_t* pos)
{
  flockfile (stream);

  /* flush buffers */
  if (stream->_oflags &= (O_WRONLY | O_RDWR)) {
    if (fflush_unlocked (stream) == EOF) {
      funlockfile (stream);
      return EOF;
    }
  }

  stream->_position = lseek (stream->_fd, *pos, SEEK_SET);
  funlockfile (stream);
  return ( stream->_position == *pos ) ? 0 : EOF;
}




uint64_t _ftell64 (FILE* stream)
{
  return ( stream->_position - ( ( (int)stream->_bufend - (int)stream->_bufidx ) + 
    (int)stream->_ungetidx ) );
}

uint64_t ftell64 (FILE* stream)
{
  uint64_t off;

  flockfile (stream);
  off = _ftell64 (stream);
  funlockfile (stream);
  return off;
}

long ftell (FILE* stream)
{
  uint64_t off;
  
  off = ftell64 (stream);
  if ( off > LONG_MAX ) {
      __seterrno (ERANGE);
      return EOF;
  }

  return off;
}

