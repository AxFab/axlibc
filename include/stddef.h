#ifndef STDDEF_H_
#define STDDEF_H_
/* ISO C99 Standard: 	<stddef.h> */

#include <errno.h>

#if defined (__cplusplus) 
extern "C" {
#endif

/* ----------------------------------------------------------------------- */


#if defined (__EX)
# define _Ko_	(1024)
# define _Mo_	(1024 * _Ko_)
# define _Go_	(1024 * _Mo_)
# define _To_	(1024 * _Go_)
# define _Po_	(1024 * _To_)
# define _Eo_	(1024 * _Po_)
# define _Zo_	(1024 * _Eo_)
# define _Yo_	(1024 * _Zo_)
#endif 

#define NULL    0
#define EOF    (-1)
#define EOL    '\n'
#define LOWER_CASE    0x20		/*< Define the flag/diff between lower case and upercase. */

typedef long ptrdiff_t;			/*< Result of pointer subtraction (type ) */
typedef unsigned long size_t;	/*< Unsigned integral type (type ) */
// typedef short wchar_t; // TODO wide char and really wide char, try to correct unicode approach

typedef long max_align_t;	/*< Type with widest scalar alignment (type ) */

#define offsetof(s,m)   (size_t)&(((s *)0)->m)

//typedef unsigned int time_t;
// typedef long pid_t;

/* ----------------------------------------------------------------------- */

#if defined (__cplusplus) 
}
#endif

#endif /* STDDEF_H_ */
