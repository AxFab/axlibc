#ifndef ASSERT_H__
#define ASSERT_H__

#include <features.h>

__AXLIBC_BEG

#ifdef NDEBUG

  // assert call will be erase by the compiler
# define assert(ignore) ((void) 0)

#else

// assert function is called if test is true
  void _assert (const char* expression, const char* function, const char* file, int line);
# define assert(test) do { if (test) _assert(#test, __func__, __FILE__, __LINE__); } while (0)

#endif

__AXLIBC_END

#endif /* ASSERT_H__ */ 
