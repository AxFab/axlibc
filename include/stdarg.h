#ifndef STDARG_H__
#define STDARG_H__

/** @file stdarg.h
 * @brief handle variable argument list
 * @version C89, C99, IEEE, Unix95, Unix98, POSIX, XSI
 *
 * The <stdarg.h> header contains a set of macros which allows portable
 * functions that accept variable argument lists to be written. Functions
 * that have variable argument lists (such as printf()) but do not use these
 * macros are inherently non-portable, as different systems use different
 * argument-passing conventions.
 */

#include <stddef.h>

__AXLIBC_BEG

/** The type va_list is defined for variables used to traverse the list.
 * The object ap may be passed as an argument to another function; if that
 * function invokes the va_arg() macro with parameter ap, the value of ap in
 * the calling function is indeterminate and must be passed to the va_end()
 * macro prior to any further reference to ap. The parameter argN is the
 * identifier of the rightmost parameter in the variable parameter list in the
 * function definition (the one just before the , ...). If the parameter argN
 * is declared with the register storage class, with a function type or array
 * type, or with a type that is not compatible with the type that results after
 * application of the default argument promotions, the behaviour is undefined.
*/
typedef char* va_list;


#define _SIZEOF(n)      (((sizeof(n))+(sizeof(void*)-1))&(~(sizeof(void*)-1)))

/** The va_start() macro is invoked to initialise ap to the beginning of the
 * list before any calls to va_arg(). */
#define va_start(ap,v)  ((ap) = (va_list)(&(v)) + _SIZEOF(v))

/** The va_arg() macro will return the next argument in the list pointed to by
 * ap. Each invocation of va_arg() modifies ap so that the values of successive
 * arguments are returned in turn. The type parameter is the type the argument
 * is expected to be. This is the type name specified such that the type of a
 * pointer to an object that has the specified type can be obtained simply by
 * suffixing a * to type. Different types can be mixed, but it is up to the
 * routine to know what type of argument is expected. */
#define va_arg(ap,t)    (*(t*) (((ap) += _SIZEOF(t)) - _SIZEOF(t)))

/** The va_end() macro is used to clean up; it invalidates ap for use
 * (unless va_start() is invoked again).  */
#define va_end(ap)      ((ap) = (va_list)0)

__AXLIBC_END

#endif /* STDARG_H__ */
