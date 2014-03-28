#ifndef DATAMODEL_H__
#define DATAMODEL_H__

/* In case _DMOVWR is not defined, we search architecture with compiler info.
 * If it is, we consider the user define also __WORD, __PROC, __ARCH and 
 * one of the datamodel macros.
 */
#ifndef _DMOVWR

// Reset all
#undef  __IP16
#undef  __LP32
#undef  __ILP32
#undef  __LLP64
#undef  __LP64
#undef  __ILP64
#undef  __SILP64

/* Architecture data model

                    IP16    LP32    ILP32   LLP64   LP64    ILP64   SILP64

    char              8       8       8       8       8       8       8
    short            16      16      16      16      16      16      64
    int              16      16      32      32      32      64      64
    long             32      32      32      32      64      64      64
    long long                        64      64      64      64      64
    pointer/size_t   16      32      32      64      64      64      64
 */


// ---------------------------------------------------------------------------
// MSVC macros
#if defined(_M_IX86) 
#define __WORD 32
#define __PROC "Intel"
#define __ARCH "i86"
#define __ILP32
#elif defined(_M_IX64)
#define __WORD 64
#define __PROC "Intel"
#define __ARCH "i64"
#define __LLP64
#elif defined(_M_X64)
#define __WORD 64
#define __PROC "AMD"
#define __ARCH "x64"
#define __LLP64
#endif
//#endif

// ---------------------------------------------------------------------------
// GCC macros
#if defined(__i386__)
#define __WORD 32
#define __PROC "Intel"
#define __ARCH "i86"
#define __ILP32
#elif defined(__ia64__) 
#define __WORD 64
#define __PROC "Intel"
#define __ARCH "i64"
#define __LP64
#elif defined(__amd64__)
#define __WORD 64
#define __PROC "AMD"
#define __ARCH "x64"
#define __LP64
#endif

#endif /* !_DMOVWR */

// ---------------------------------------------------------------------------
// Check validity of architecture
#if (!defined(__WORD)) || (!defined(__PROC)) || (!defined(__ARCH))
#error Unable to get architecture details
#endif


// ---------------------------------------------------------------------------
// Define pointer size 
#if defined(__IP16)
#  define __POINTER_BITS  16
#elif defined(__LP32) || defined (__ILP32)
#  define __POINTER_BITS  32
#elif defined(__LLP64) || defined (__LP64) || defined(__ILP64) || defined (__SILP64)
#  define __POINTER_BITS  64
#else
#  error Unsuported data model
#endif

// ---------------------------------------------------------------------------
// Define number size
#define __CHAR_BITS      8

#if defined (__SILP64)
#  define __SHORT_BITS    64
#else
#  define __SHORT_BITS    16
#endif

#if defined (__IP16) || defined (__LP32)
#  define __INT_BITS      16
#elif defined (__ILP32) || defined(__LLP64) || defined (__LP64)
#  define __INT_BITS      32
#else
#  define __INT_BITS      64
#endif

#if defined (__IP16) || defined (__LP32) || defined (__ILP32) || defined(__LLP64)
#  define __LONG_BITS     32
#else
#  define __LONG_BITS     64
#endif

#if __POINTER_BITS == 64 || defined (__ILP32)
#  define __LLONG_BITS    64
#endif



#endif /* DATAMODEL_H__ */
