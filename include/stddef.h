#ifndef STDDEF_H__
#define STDDEF_H__
#include <sys/version.h>
/* ISO C99 Standard: 	<stddef.h> */


#define NULL    0
#define EOF    (-1)
#define EOL    '\n'
#define LOWER_CASE    0x20		/*< Define the flag/diff between lower case and upercase. */

typedef long ptrdiff_t;			/*< Result of pointer subtraction (type ) */
typedef unsigned long size_t;	/*< Unsigned integral type (type ) */
// typedef short wchar_t; // TODO wide char and really wide char, try to correct unicode approach
typedef size_t fpos_t;
typedef long int off_t;
typedef long int wchar_t;


typedef long max_align_t;	/*< Type with widest scalar alignment (type ) */

#define offsetof(s,m)   (size_t)&(((s *)0)->m)

//typedef unsigned int time_t;
// typedef long pid_t;



#endif /* STDDEF_H__ */
