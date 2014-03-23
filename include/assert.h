#ifndef ASSERT_H__
#define ASSERT_H__
#include <sys/version.h>
/* ISO C89 Standard */

#ifdef NDEBUG
#define assert(ignore)((void) 0)
#else
void _assert (int test, const char* expression, const char* function, const char* file, int line);
#define assert(test) _assert((int)(test), #test, __func__, __FILE__, __LINE__)
#endif

#endif /* ASSERT_H__ */ 
