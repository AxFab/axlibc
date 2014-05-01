#include <stream.h>

// ---------------------------------------------------------------------------
void clearerr (FILE* stream)
{
  flockfile (stream);
  stream->_oflags &= ~(OF_ERR | OF_EOF);
  funlockfile (stream);
}

// ---------------------------------------------------------------------------
int feof (FILE* stream)
{
  return stream->_oflags & OF_EOF;
}


// ---------------------------------------------------------------------------
int ferror (FILE* stream)
{
  return stream->_oflags & OF_ERR;
}


// ---------------------------------------------------------------------------
int fileno (FILE* stream)
{
  return stream->_fd;
}

