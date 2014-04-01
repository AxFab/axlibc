#ifndef ASSERT_H__
#define ASSERT_H__

/** @file assert.h
 * @brief verify program assertion 
 * @version C89, C99, Unix95, Unix98, POSIX, XSI
 * 
 * The <assert.h> header defines the assert() macro. It refers to the macro 
 * NDEBUG which is not defined in the header. If NDEBUG is defined as a macro 
 * name before the inclusion of this header, the assert() macro will be 
 * removed by the compiler. Otherwise the macro behaves as described in 
 * assert().
 * The assert() macro is implemented as a macro, not as a function. If the 
 * macro definition is suppressed in order to access an actual function, the 
 * behaviour is undefined. 
 */

#include <features.h>

__AXLIBC_BEG

#ifdef NDEBUG

// assert call will be erase by the compiler
# define assert(ignore) ((void) 0)

#else

// assert function is called if test is true
# define assert(test) do {                                      \
      _assert(test, #test, __func__, __FILE__, __LINE__);       \
    } while (0)


/** 
 * If the assertion test is false, the program will print the reason for the 
 * assertion an leave the program. in other case this routines have no effect.
 */
void _assert (int test, const char* expression, const char* function, 
    const char* file, int line);

#endif

__AXLIBC_END

#endif /* ASSERT_H__ */ 
