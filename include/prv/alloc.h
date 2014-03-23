#pragma once
/* OS Libc Implementation: 	<prv/alloc.h> */

#ifndef __ALLOC_H_
#define __ALLOC_H_

#include <stddef.h>
#include <stdint.h>

/* Private Macros ---------------------------------------------------------- */
#define ALLOC_MAX_CHUNK		0x30000000
#define ALLOC_MIN_CHUNK		sizeof(xHeapChunk_t)
#define	ALLOC_CHUNK_HEAD	(sizeof (uint32_t)*4)
#define alloc_chunk(p)		((xHeapChunk_t*)((uint32_t)(p) - ALLOC_CHUNK_HEAD))

#define ALLOC_CHECK		0x01
#define ALLOC_ISUSED		0x01
#define ALLOC_CORRUPTED     0x02
#define ALLOC_PARANOID     0x04

#define ALIGN(v,a)      (((v)+(a-1))&(~(a-1)))
#define _LOCK(h)        ((void)(0))
#define _UNLOCK(h)        ((void)(0))

/* Structures definitions -------------------------------------------------- */
typedef struct xHeapChunk xHeapChunk_t;
struct xHeapChunk {
    uint32_t prev_size;
    uint32_t reserved;
    uint32_t chunk_size;
    uint32_t is_used;
    union {
		// If the block is empty
        struct { 
        	xHeapChunk_t* prev_chunk;
        	xHeapChunk_t* next_chunk;
        };
		// If the block is used
        uint32_t data[4];
    };
};

typedef struct xHeapArea xHeapArea_t;
struct xHeapArea {
	xHeapChunk_t* start;
	xHeapChunk_t* free_list;
    size_t max;
    size_t available;
	char lock;
	long flags;
};

/* Functions --------------------------------------------------------------- */
#define valloc(n) memalign_r(heap, PAGE_SIZE, (n))
#define pvalloc(n) memalign_r(heap, PAGE_SIZE, ALIGN(n, PAGE_SIZE))

/**
 * @brief Initialize a heap segment structure info
 */
void meminit_r(xHeapArea_t* heap, void* base, size_t length);

/**
 * @brief allocate dynamic memory 
 * @return The malloc() and calloc() functions return a pointer to the 
 * allocated memory that is suitably aligned for any kind of variable. On
 * error, these functions return NULL. NULL may also be returned by a 
 * successful call to malloc() with a size of zero, or by a successful call to 
 * calloc() with nmemb or size equal to zero. 
 *
 * The malloc() function allocates size bytes and returns a pointer to the 
 * allocated memory. The memory is not initialized. If size is 0, then 
 * malloc() returns either NULL, or a unique pointer value that can later be 
 * successfully passed to free(). 
 *
 * @see malloc, free, calloc, realloc
 * @see brk, mmap, alloca, malloc_get_state, malloc_info, malloc_trim, 
 * malloc_usable_size, mallopt, mcheck, mtrace, posix_memalign 
 * @note By default, the kernel follows an optimistic memory allocation 
 * strategy. This means that when malloc() returns non-NULL there is no 
 * guarantee that the memory really is available. In case it turns out that 
 * the system is out of memory, one or more processes will be killed. 
 */
void* malloc_r(xHeapArea_t* heap, size_t size);

/**
 * @brief free dynamic memory 
 * @return The free() function returns no value.
 * 
 * The free() function frees the memory space pointed to by ptr, which must 
 * have been returned by a previous call to malloc(), calloc() or realloc(). 
 * Otherwise, or if free(ptr) has already been called before, undefined 
 * behavior occurs. If ptr is NULL, no operation is performed.
 *
 * @see malloc, free, calloc, realloc
 * @see brk, mmap, alloca, malloc_get_state, malloc_info, malloc_trim, 
 * malloc_usable_size, mallopt, mcheck, mtrace, posix_memalign 
 */
void free_r(xHeapArea_t* heap, void* ptr);

/**
 * @brief allocate dynamic memory 
 * @return The realloc() function returns a pointer to the newly allocated 
 * memory, which is suitably aligned for any kind of variable and may be 
 * different from ptr, or NULL if the request fails. If size was equal to 0, 
 * either NULL or a pointer suitable to be passed to free() is returned. If 
 * realloc() fails the original block is left untouched; it is not freed or
 * moved. 
 *
 * The realloc() function changes the size of the memory block pointed to by 
 * ptr to size bytes. The contents will be unchanged in the range from the 
 * start of the region up to the minimum of the old and new sizes. If the new 
 * size is larger than the old size, the added memory will not be initialized.
 * If ptr is NULL, then the call is equivalent to malloc(size), for all values 
 * of size; if size is equal to zero, and ptr is not NULL, then the call is 
 * equivalent to free(ptr). Unless ptr is NULL, it must have been returned by 
 * an earlier call to malloc(), calloc() or realloc(). If the area pointed to 
 * was moved, a free(ptr) is done. 
 *
 * @see malloc, free, calloc, realloc
 * @see brk, mmap, alloca, malloc_get_state, malloc_info, malloc_trim, 
 * malloc_usable_size, mallopt, mcheck, mtrace, posix_memalign 
 */
void* realloc_r(xHeapArea_t* heap, void* ptr, size_t size);

/**
 * @brief allocate aligned memory 
 * @return aligned_alloc(), memalign(), valloc(), and pvalloc() return a 
 * pointer to the allocated memory, or NULL if the request fails. 
 * 
 * The obsolete function memalign() allocates size bytes and returns a pointer 
 * to the allocated memory. The memory address will be a multiple of alignment, 
 * which must be a power of two. 
 *
 * @throw EINVAL - The alignment argument was not a power of two, or was not a 
 * multiple of sizeof(void *).
 * @throw ENOMEM - There was insufficient memory to fulfill the allocation 
 * request. 
 * @see posix_memalign, aligned_alloc, memalign, valloc, pvalloc
 * @see brk, mmap, alloca, malloc_get_state, malloc_info, malloc_trim, 
 * malloc_usable_size, mallopt, mcheck, mtrace, posix_memalign 
 */
void* memalign_r(xHeapArea_t* heap, size_t alignment, size_t size);

/**
 * @brief retrace the heap to detect memory corruption
 * @return zero if the heap is not corrupted, non zero is errors have been
 * detected.
 *
 * Browse the list of block on address order check consistency and count
 * the number of blocks. Compare that to the free list and check list 
 * consistency.
 */
int memcorrupt_r (xHeapArea_t* heap);

#endif /* __ALLOC_H_ */
