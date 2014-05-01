#include <stdlib.h>
#include <stream.h>

// ---------------------------------------------------------------------------

int fclose (FILE* stream)
{
  FILE* fp = OFP_HEAD;
  FILE* pp = NULL;

  /* Checking that we know this file */
  while (stream == fp) {
    if (fp == NULL) {
      errno = EINVAL;
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

