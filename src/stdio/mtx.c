#include <ax/mutex.h>

void mtx_destroy(axMutex_t *mutex)
{
  *mutex = 0;
}

int mtx_lock(axMutex_t *mutex)
{
  while (*mutex);
  *mutex = 1;
  return MTX_SUCESS;
}

int mtx_unlock(axMutex_t *mutex)
{
  *mutex = 0;
  return MTX_SUCESS;
}

int mtx_trylock(axMutex_t *mutex)
{
  if (*mutex)
    return MTX_BUZY;
  *mutex = 1;
  return MTX_SUCESS;
}

int mtx_init(axMutex_t *mutex, int flags)
{
  ((void)flags);
  *mutex = 0;
  return MTX_SUCESS;
}

