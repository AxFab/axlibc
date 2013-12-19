#include <stdlib.h> // abort
#include <prv/stream.h>


// ---------------------------------------------------------------------------
void flockfile (FILE* stream)
{
  if(mtx_lock( &stream->_lock ) != MTX_SUCESS ) {
    abort();
  }
}

// ---------------------------------------------------------------------------
void funlockfile (FILE* stream)
{
  if (mtx_unlock( &stream->_lock ) != MTX_SUCESS) {
    abort();
  }
}

// ---------------------------------------------------------------------------
int ftrylockfile (FILE* stream)
{
  switch(mtx_trylock( &stream->_lock )) {
    
    case MTX_SUCESS:
      return 0;

    case MTX_BUZY:
      return 1;

    default:
      abort();
  }
}
