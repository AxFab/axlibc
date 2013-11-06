#ifndef STDBOOL_H_
#define STDBOOL_H_
/* ISO C99 Standard: */

#include <__std.h>

#if !(defined(__C99) || defined(__EX))
#  error stdbool is not available, use ISO C99 Standard. 
#endif

#if defined (__cplusplus) 
extern "C" {
#endif

/* ----------------------------------------------------------------------- */


#define	__bool_true_false_are_defined	1

#define	false 0
#define	true (!0)
#define	bool _Bool
// typedef	char _Bool ;

/* ----------------------------------------------------------------------- */

#if defined (__cplusplus) 
}
#endif

#endif /* STDBOOL_H_ */
