#ifndef AX_MUTEX_H__
#define AX_MUTEX_H__

typedef int axMutex_t;

void mtx_destroy(axMutex_t *mutex);
int mtx_lock(axMutex_t *mutex);
int mtx_unlock(axMutex_t *mutex);
int mtx_trylock(axMutex_t *mutex);
int mtx_init(axMutex_t *mutex, int flags);

#define MTX_RECURSIVE 8
#define MTX_SUCESS  0
#define MTX_BUZY  1

#endif /* AX_MUTEX_H__ */
