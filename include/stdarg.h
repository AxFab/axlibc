#ifndef STDARG_H__
#define STDARG_H__
/* ISO C89 Standard:  <stdarg.h> */

#include <stddef.h>

__AXLIBC_BEG

typedef char* va_list;

#define _SIZEOF(n)      ALIGN(sizeof(n), sizeof(void*))

#define va_start(ap,v)  ((ap) = (va_list)(&(v)) + _SIZEOF(v))
#define va_arg(ap,t)    (*(t*) (((ap) += _SIZEOF(t)) - _SIZEOF(t)))
#define va_end(ap)      ((ap) = (va_list)0)

__AXLIBC_END

#endif /* STDARG_H__ */
