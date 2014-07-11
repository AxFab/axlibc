#ifndef STDDEF_H__
#define STDDEF_H__

/** @file stddef.h
 * @brief standard type definitions 
 * @version C89, C99, IEEE, Unix95, Unix98, POSIX, XSI
 * 
 * The <stddef.h> header defines the following: 
 */

#include <features.h>
#include <datamodel.h>

__AXLIBC_BEG

/** Null pointer constant. */
#define NULL    0             

/** Integral constant expression of type size_t, the value of which is the
 * offset in bytes to the structure member (member-designator), from the
 * beginning of its structure (type). 
 */
#define offsetof(s,m)   (size_t)&(((s *)0)->m)

#ifndef _SIZE_DEF
#  define _SIZE_DEF
#  if __POINTER_BITS == __INT_BITS
    typedef unsigned int size_t;	/**< Unsigned integral type (type ) */
    typedef int ptrdiff_t;     /**< Result of pointer subtraction (type ) */
#  elif __POINTER_BITS == __LONG_BITS
    typedef unsigned long size_t;  /**< Unsigned integral type (type ) */
    typedef long ptrdiff_t;     /**< Result of pointer subtraction (type ) */
#  else
    typedef unsigned long long size_t;  /**< Unsigned integral type (type ) */
    typedef long long ptrdiff_t;     /**< Result of pointer subtraction (type ) */
#  endif
#endif


/** Integral type whose range of values can represent distinct wide-character 
 * codes for all members of the largest character set specified among the 
 * locales supported by the compilation environment: the null character has the 
 * code value 0 and each member of the Portable Character Set has a code value 
 * equal to its value when used as the lone character in an integer character 
 * constant. 
 */
typedef int wchar_t;


__AXLIBC_END

#endif /* STDDEF_H__ */
