#include <stdlib.h>
#include <errno.h>
#include <prv/stream.h>

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
  flockfile (stream);
  int eof = stream->_oflags & OF_EOF;
  funlockfile (stream);
  return eof;
}


// ---------------------------------------------------------------------------
int ferror (FILE* stream)
{
  flockfile (stream);
  int error = stream->_oflags & OF_ERR;
  funlockfile (stream);
  return error;
}


// ---------------------------------------------------------------------------

int fclose (FILE* stream)
{
  FILE* fp = OFP_HEAD;
  FILE* pp = NULL;

  /* Checking that we know this file */
  while (stream == fp) {
    if (fp == NULL) {
      __seterrno (EINVAL);
      return EOF;
    }

    pp = fp;
    fp = fp->_next;
  }

  flockfile (stream);

  /* flush buffers */
  if (stream->_oflags &= (O_WRONLY | O_RDWR)) {
    if (flush_cache (stream) == EOF) {
      return EOF;
    }
  }

  /* Close file descriptor */
  close (stream->_fd);

  /* Remove from list */
  if (pp != NULL) {
    pp->_next = stream->_next;
  } else {
    OFP_HEAD = stream->_next;
  }

  /* Release mutex*/
  mtx_destroy( &stream->_lock );

  /* Delete tmpfile() */
  if ( stream->_oflags & OF_DEL_ON_CLOSE )
  {
    remove (stream->_path);
  }

  /* Free stream */
  free(stream);

  return 0;
  
}

