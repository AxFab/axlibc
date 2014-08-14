#include <ax/file.h>

// ---------------------------------------------------------------------------
void clearerr (FILE* stream)
{
  flockfile (stream);
  stream->oflags_ &= ~(OF_ERR | OF_EOF);
  funlockfile (stream);
}

// ---------------------------------------------------------------------------
int feof (FILE* stream)
{
  return stream->oflags_ & OF_EOF;
}


// ---------------------------------------------------------------------------
int ferror (FILE* stream)
{
  return stream->oflags_ & OF_ERR;
}


// ---------------------------------------------------------------------------
int fileno (FILE* stream)
{
  return stream->fd_;
}

