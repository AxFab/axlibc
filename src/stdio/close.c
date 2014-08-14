#include <stdlib.h>
#include <ax/file.h>
#include <fcntl.h>
#include <errno.h>

// ---------------------------------------------------------------------------

int fclose (FILE* fp)
{
  FILE* hp = OFP_HEAD;
  FILE* pp = NULL;

  /* Checking that we know this file */
  while (fp == hp) {
    if (fp == NULL) {
      errno = EINVAL;
      return EOF;
    }

    pp = fp;
    fp = fp->next_;
  }

  flockfile (fp);

  /* flush buffers */
  if (fp->oflags_ &= (O_WRONLY | O_RDWR)) {
    if (flush_cache (fp) == EOF) {
      return EOF;
    }
  }

  /* Close file descriptor */
  close (fp->fd_);

  /* Remove from list */
  if (pp != NULL) {
    pp->next_ = fp->next_;
  } else {
    OFP_HEAD = fp->next_;
  }

  /* Release mutex*/
  mtx_destroy( &fp->lock_ );

  /* Free fp */
  free(fp);

  return 0;

}

