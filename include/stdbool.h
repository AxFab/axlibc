#ifndef STDBOOL_H_
#define STDBOOL_H_
#include <features.h>

#if !(defined(__C99) || defined(__EX))
#  error stdbool is not available, use ISO C99 Standard. 
#endif

__AXLIBC_BEG
/* ----------------------------------------------------------------------- */


#define	__bool_true_false_are_defined	1

#define	false 0
#define	true (!0)
#define	bool _Bool
// typedef	char _Bool ;

/* ----------------------------------------------------------------------- */

__AXLIBC_END

#endif /* STDBOOL_H_ */
