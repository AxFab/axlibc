#ifndef SETJMP_H__
#define SETJMP_H__

/** @file setjmp.h
 * @brief stack environment declarations 
 * @version C89, C99, IEEE, Unix95, Unix98, POSIX, XSI
 * 
 * The <setjmp.h> header contains the type definitions for array types jmp_buf 
 * and sigjmp_buf.
 */

#include <stddef.h>

__AXLIBC_BEG

// ===========================================================================
/**
 * The longjmp() function restores the environment saved by the most recent 
 * invocation of setjmp() in the same thread, with the corresponding jmp_buf 
 * argument. If there is no such invocation, or if the function containing the 
 * invocation of setjmp() has terminated execution in the interim, the
 * behaviour is undefined. It is unspecified whether longjmp() restores the 
 * signal mask, leaves the signal mask unchanged or restores it to its value at 
 * the time setjmp() was called. 
 *
 * @return fter longjmp() is completed, program execution continues as if the 
 * corresponding invocation of setjmp() had just returned the value specified 
 * by val. The longjmp() function cannot cause setjmp() to return 0; if val is
 * 0, setjmp() returns 1. 
 */
void longjmp(jmp_buf env, int val);


/** A call to setjmp(), saves the calling environment in its env argument for 
 * later use by longjmp().
 * It is unspecified whether setjmp() is a macro or a function. If a macro 
 * definition is suppressed in order to access an actual function, or a program 
 * defines an external identifier with the name setjmp the behaviour is 
 * undefined.
 * All accessible objects have values as of the time longjmp() was called, 
 * except that the values of objects of automatic storage duration which are 
 * local to the function containing the invocation of the corresponding 
 * setjmp() which do not have volatile-qualified type and which are changed 
 * between the setjmp() invocation and longjmp() call are indeterminate. 
 *
 * @return If the return is from a direct invocation, setjmp() returns 0. If 
 * the return is from a call to longjmp(), setjmp() returns a non-zero value. 
 */
int setjmp(jmp_buf env);


// ===========================================================================
/**
 * The siglongjmp() function restores the environment saved by the most recent
 * invocation of sigsetjmp() in the same thread, with the corresponding 
 * sigjmp_buf argument. If there is no such invocation, or if the function 
 * containing the invocation of sigsetjmp() has terminated execution in the
 * interim, the behaviour is undefined.
 * All accessible objects have values as of the time sigsetjmp() was called, 
 * except that the values of objects of automatic storage duration which are 
 * local to the function containing the invocation of the corresponding 
 * sigsetjmp() which do not have volatile-qualified type and which are changed 
 * between the sigsetjmp() invocation and siglongjmp() call are indeterminate.
 * As it bypasses the usual function call and return mechanisms, siglongjmp() 
 * will execute correctly in contexts of interrupts, signals and any of their 
 * associated functions. However, if siglongjmp() is invoked from a nested 
 * signal handler (that is, from a function invoked as a result of a signal 
 * raised during the handling of another signal), the behaviour is undefined.
 * The siglongjmp() function will restore the saved signal mask if and only if 
 * the env argument was initialised by a call to sigsetjmp() with a non-zero 
 * savemask argument.
 * The effect of a call to siglongjmp() where initialisation of the jmp_buf 
 * structure was not performed in the calling thread is undefined. 
 *
 * @return After siglongjmp() is completed, program execution continues as if 
 * the corresponding invocation of sigsetjmp() had just returned the value 
 * specified by val. The siglongjmp() function cannot cause sigsetjmp() to 
 * return 0; if val is 0, sigsetjmp() returns the value 1. 
 */
void siglongjmp(sigjmp_buf env, int val);

/** A call to sigsetjmp() saves the calling environment in its env argument for 
 * later use by siglongjmp(). It is unspecified whether sigsetjmp() is a macro
 * or a function. If a macro definition is suppressed in order to access an 
 * actual function, or a program defines an external identifier with the name 
 * sigsetjmp the behaviour is undefined.
 * If the value of the savemask argument is not 0, sigsetjmp() will also save 
 * the current signal mask of the calling thread as part of the calling 
 * environment.
 * All accessible objects have values as of the time siglongjmp() was called, 
 * except that the values of objects of automatic storage duration which are
 * local to the function containing the invocation of the corresponding 
 * sigsetjmp() which do not have volatile-qualified type and which are changed 
 * between the sigsetjmp() invocation and siglongjmp() call are indeterminate. 
 *
 * @return If the return is from a successful direct invocation, sigsetjmp() 
 * returns 0. If the return is from a call to siglongjmp(), sigsetjmp() returns
 * a non-zero value. 
 */
int    sigsetjmp(sigjmp_buf, int);


// ===========================================================================
/** 
 * The _longjmp() and _setjmp() functions are identical to longjmp() and
 * setjmp(), respectively, with the additional restriction that _longjmp() and 
 * _setjmp() do not manipulate the signal mask.
 * If _longjmp() is called even though env was never initialised by a call to 
 * _setjmp(), or when the last such call was in a function that has since 
 * returned, the results are undefined. 
 */
void _longjmp(jmp_buf env, int val);

/** 
 * The _longjmp() and _setjmp() functions are identical to longjmp() and
 * setjmp(), respectively, with the additional restriction that _longjmp() and 
 * _setjmp() do not manipulate the signal mask.
 * If _longjmp() is called even though env was never initialised by a call to 
 * _setjmp(), or when the last such call was in a function that has since 
 * returned, the results are undefined. 
 */
int _setjmp(jmp_buf env);


__AXLIBC_END

#endif /* SETJMP_H__ */
