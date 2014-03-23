#ifndef SYS_VERSION_H__
#define SYS_VERSION_H__

//#if MSVC
#if defined(_M_IX86) 
#define __WORD 32
#define __PROC "Intel"
#define __ARCH "i86"
#elif defined(_M_IX64)
#define __WORD 64
#define __PROC "Intel"
#define __ARCH "i64"
#elif defined(_M_X64)
#define __WORD 64
#define __PROC "AMD"
#define __ARCH "x64"
#endif
//#endif

//#if GCC
#if defined(__i386__)
#define __WORD 32
#define __PROC "Intel"
#define __ARCH "i86"
#elif defined(__ia64__) 
#define __WORD 64
#define __PROC "Intel"
#define __ARCH "i64"
#elif defined(__amd64__)
#define __WORD 64
#define __PROC "AMD"
#define __ARCH "x64"
#endif
//#endif


#define __CHAR_BITS    8
#define __SHORT_BITS  16
#define __INT_BITS    32
#define __LONG_BITS   32
#define __LLONG_BITS  64



#if (!defined(__WORD)) || (!defined(__PROC)) || (!defined(__ARCH))
#error Unable to get architecture details
#endif

#if (!defined(__CHAR_BITS)) || (!defined(__SHORT_BITS)) || \
    (!defined(__INT_BITS)) || (!defined(__LONG_BITS))
#error Unable to define word size
#endif


#endif /* SYS_VERSION_H__ */
