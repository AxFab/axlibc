#ifndef STDDEF_H__
#define STDDEF_H__

#include <features.h>
#include <datamodel.h>

__AXLIBC_BEG

#define NULL    0
#define EOF    (-1)
#define EOL    '\n'
#define LOWER_CASE    0x20		/*< Define the flag/diff between lower case and upercase. */


#if __POINTER_BITS == __INT_BITS
  typedef unsigned int size_t;	/*< Unsigned integral type (type ) */
  typedef int ptrdiff_t;     /*< Result of pointer subtraction (type ) */
#elif __POINTER_BITS == __LONG_BITS
  typedef unsigned long size_t;  /*< Unsigned integral type (type ) */
  typedef long ptrdiff_t;     /*< Result of pointer subtraction (type ) */
#else
  typedef unsigned long long size_t;  /*< Unsigned integral type (type ) */
  typedef long long ptrdiff_t;     /*< Result of pointer subtraction (type ) */
#endif



// typedef short wchar_t; // TODO wide char and really wide char, try to correct unicode approach
typedef size_t fpos_t;
typedef long int wchar_t;


typedef long max_align_t;	/*< Type with widest scalar alignment (type ) */

#define offsetof(s,m)   (size_t)&(((s *)0)->m)

//typedef unsigned int time_t;
// typedef long pid_t;

__AXLIBC_END

#endif /* STDDEF_H__ */
