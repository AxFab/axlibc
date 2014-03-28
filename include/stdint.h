#ifndef STDINT_H_
#define STDINT_H_
#include <datamodel.h>
#include <features.h>

__AXLIBC_BEG

#if !(defined(__C99) || defined(__EX))
#  error stdint is not available, use ISO C99 Standard. 
#endif

/* ----------------------------------------------------------------------- */

typedef signed char int8_t;         /*< 8-bit signed type. */
typedef unsigned char uint8_t;        /*< 8-bit unsigned type. */

#if __WORD == 16

typedef signed int int16_t;       /*< 16-bit signed type. */
typedef unsigned int uint16_t;      /*< 16-bit unsigned type. */

typedef signed long int32_t;         /*< 32-bit signed type. */
typedef unsigned long uint32_t;        /*< 32-bit unsigned type. */

#elif __WORD == 32 || __WORD == 64

typedef signed short int16_t;       /*< 16-bit signed type. */
typedef unsigned short uint16_t;      /*< 16-bit unsigned type. */

typedef signed int int32_t;         /*< 32-bit signed type. */
typedef unsigned int uint32_t;        /*< 32-bit unsigned type. */

typedef signed long long int int64_t;   /*< 64-bit signed type. */
typedef unsigned long long int uint64_t;  /*< 64-bit unsigned type. */

#endif


#if __WORD == 16

typedef int16_t intptr_t;         /* Signed pointer compatible type. */
typedef uint16_t uintptr_t;         /* Unsigned pointer compatible type. */

#elif __WORD == 32

typedef int32_t intptr_t;         /* Signed pointer compatible type. */
typedef uint32_t uintptr_t;         /* Unsigned pointer compatible type. */

#elif __WORD == 64

typedef int64_t intptr_t;         /* Signed pointer compatible type. */
typedef uint64_t uintptr_t;         /* Unsigned pointer compatible type. */

#endif


typedef int8_t   int_least8_t;
typedef uint8_t  uint_least8_t;

typedef int32_t  int_least16_t;
typedef uint32_t uint_least16_t;

typedef int32_t  int_least32_t;
typedef uint32_t uint_least32_t;

typedef int64_t  int_least64_t;
typedef uint64_t uint_least64_t;



typedef signed char int_fast8_t;
typedef unsigned char uint_fast8_t;

typedef signed int int_fast16_t;
typedef unsigned int uint_fast16_t;

typedef signed long int_fast32_t;
typedef signed long uint_fast32_t;

typedef signed long long int_fast64_t;
typedef signed long long uint_fast64_t;



typedef int64_t intmax_t;
typedef uint64_t uintmax_t;



#define INT8_MAX 0x7f
#define INT8_MIN (-INT8_MAX - 1)

#define INT16_MAX 0x7fff
#define INT16_MIN (-INT16_MAX - 1)
#define UINT16_MAX (INT16_MAX * 2U + 1U)

#define INT32_MAX 0x7fffffff
#define INT32_MIN (-INT32_MAX - 1L)
#define UINT32_MAX (INT32_MAX * 2UL + 1UL)

#define INT64_MAX 0x7fffffffffffffffLL
#define INT64_MIN (-INT64_MAX - 1LL)
#define UINT64_MAX (INT64_MAX * 2ULL + 1ULL)

#define INT_LEAST8_MAX INT8_MAX
#define INT_LEAST8_MIN INT8_MIN
#define UINT_LEAST8_MAX UINT8_MAX
#define INT_LEAST16_MAX INT16_MAX
#define INT_LEAST16_MIN INT16_MIN
#define UINT_LEAST16_MAX UINT16_MAX
#define INT_LEAST32_MAX INT32_MAX
#define INT_LEAST32_MIN INT32_MIN
#define UINT_LEAST32_MAX UINT32_MAX
#define INT_LEAST64_MAX INT64_MAX
#define INT_LEAST64_MIN INT64_MIN
#define UINT_LEAST64_MAX UINT64_MAX

#define INT_FAST8_MAX INT8_MAX
#define INT_FAST8_MIN INT8_MIN
#define UINT_FAST8_MAX UINT8_MAX
#define INT_FAST16_MAX INT16_MAX
#define INT_FAST16_MIN INT16_MIN
#define UINT_FAST16_MAX UINT16_MAX
#define INT_FAST32_MAX INT32_MAX
#define INT_FAST32_MIN INT32_MIN
#define UINT_FAST32_MAX UINT32_MAX
#define INT_FAST64_MAX INT64_MAX
#define INT_FAST64_MIN INT64_MIN
#define UINT_FAST64_MAX UINT64_MAX

#define INTPTR_MAX INT32_MAX
#define INTPTR_MIN INT32_MIN
#define UINTPTR_MAX UINT32_MAX
#define INTMAX_MAX INT64_MAX
#define INTMAX_MIN INT64_MIN
#define UINTMAX_MAX UINT64_MAX

#define PTRDIFF_MAX INT32_MAX
#define PTRDIFF_MIN INT32_MIN

#define SIG_ATOMIC_MAX INT8_MAX
#define SIG_ATOMIC_MIN INT8_MIN

#define SIZE_MAX ((uint32_t)INT32_MAX)


#define INT8_C(value) ((int8_t) value)
#define UINT8_C(value) ((uint8_t) value)

#define INT16_C(value) ((int16_t) value)
#define UINT16_C(value) ((uint16_t) value)

#define INT32_C(value) ((int32_t) value)
#define UINT32_C(value) ((uint32_t) value)

#define INT64_C(value) ((int64_t) value)
#define UINT64_C(value) ((uint64_t) value)

#define INTMAX_C(value) ((intmax_t) value)
#define UINTMAX_C(value) ((uintmax_t) value)

/* ----------------------------------------------------------------------- */

__AXLIBC_END

#endif /* STDINT_H_ */
