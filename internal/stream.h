#ifndef PRV_STREAM_H__
#define PRV_STREAM_H__

#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <unistd.h>

#include <error.h>



// #define O_RDONLY		1
// #define O_WRONLY		2
// #define O_RDWR			4
// #define O_APPEND		8
// #define O_CREAT			16
// #define O_TRUNC			32

// #define O_BINARY   64
// #define O_EXCL   128
// #define O_CLOEXEC  256
// #define O_MEMORYMAP   512
// #define O_LARGEFILE   1024

#define OF_DEL_ON_CLOSE  0x800

#define OF_EOF		0x1000
#define OF_ERR		0x2000

#define OF_RIGHTS  0644

#define UNGET_BUFSIZ 8
typedef int axMutex_t;
typedef struct axStream FILE;

struct axStream 
{
	int _fd;
	int _oflags;
	int _name;
	fpos_t _position;
	axMutex_t _lock;
	FILE* _next;
	char* _path;
	uint8_t* _cache;
	uint8_t _ungetbuf[UNGET_BUFSIZ];
	size_t _bufsize;
	size_t _bufidx;
	size_t _bufend;
	size_t _ungetidx;
	void (*_close)(int);
};

void mtx_destroy(axMutex_t *mutex);
int mtx_lock(axMutex_t *mutex);
int mtx_unlock(axMutex_t *mutex);
int mtx_trylock(axMutex_t *mutex);
int mtx_init(axMutex_t *mutex, int flags);
#define MTX_RECURSIVE 8
#define MTX_SUCESS	0
#define MTX_BUZY	1


void flockfile (FILE* restrict stream);
void funlockfile (FILE* restrict stream);
int ftrylockfile (FILE* restrict stream);


int fflush_unlocked (FILE* restrict stream);


int fill_cache (FILE* stream);
int flush_cache (FILE* stream);


extern FILE* OFP_HEAD;



#endif /* PRV_STREAM_H__ */
