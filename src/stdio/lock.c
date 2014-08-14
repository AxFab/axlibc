#include <stdlib.h> // abort
#include <ax/file.h>
#include <ax/mutex.h>


// ---------------------------------------------------------------------------
void flockfile (FILE* fp)
{
  if(mtx_lock( &fp->lock_ ) != MTX_SUCESS ) {
    abort();
  }
}

// ---------------------------------------------------------------------------
void funlockfile (FILE* fp)
{
  if (mtx_unlock( &fp->lock_ ) != MTX_SUCESS) {
    abort();
  }
}

// ---------------------------------------------------------------------------
int ftrylockfile (FILE* fp)
{
  switch(mtx_trylock( &fp->lock_ )) {

    case MTX_SUCESS:
      return 0;

    case MTX_BUZY:
      return 1;

    default:
      abort();
  }
}
