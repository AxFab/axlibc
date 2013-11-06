#ifndef __STD_H_
#define __STD_H_

/* Version ------------------------------------------------------------------

                BSD     AX
	          /     \ /
	BSC _ C89 _ C99 _ _ U95 _ U98 _ POSIX

		BSC : 
		C89 : contains all of BSC
		C99 : contains all of C89
		BSD : contains all of C89
		AX : contains all of C99 and BSD
		U95 : contains all of C99 and BSD
		U98 : contains all of U95
		U03 : contains all of U98

	Extention
		GCC : GNU compiler
		SUZ : Open Suze
		FLT : Floating number
		EX : Used only to load stdint and stdbool for BSC
		LOC : Add local stuff
 */

#ifdef __BSC
#  define __EX
#endif

#ifdef __U03
#  define __U98
#endif

#ifdef __U98
#  define __U95
#endif

#if defined(__U95) || defined(__AX)
#  define __C99
#  define __BSD
#endif

#if defined(__C99) || defined(__BSD)
#  define __C89
#endif

#if !(defined(__C89) || defined(__BSC))
#  error no version found
#endif

#define _LIBC_MAJOR_VERSION     1
#define _LIBC_MINOR_VERSION     0
#define _LIBC_PATCHLEVEL        0

#define _LIBC_VERSION           #_LIBC_MAJOR_VERSION "." \
								#_LIBC_MINOR_VERSION "." \
								#_LIBC_PATCHLEVEL

/* Minimum library used -------------------------------------------------- */
#include <limits.h>
#include <stddef.h>

#if defined(__C99) || defined(__EX)
#  include <stdint.h>
#  include <stdbool.h>
#endif

/* Compiler symbols attributes ------------------------------------------- */
#ifndef _MSC_VER
#   define _noreturn	__attribute__ ((noreturn))
#   define _pure		__attribute__ ((pure))
#   define _in
#   define _out
#   define _ref
#   define PACK(Decl)	Decl __attribute__((__packed__))
#else
#   define _noreturn	__declspec(noreturn)
#   define _pure
#   define _in
#   define _out
#   define _ref
#   define PACK(Decl)	__pragma( pack(push, 1) ) Decl __pragma( pack(pop) )
#endif


#if defined (__cplusplus) 
extern "C" {
#endif

/* Usefull macro --------------------------------------------------------- */
#define _LOCK(s)		cpu_lock(&((s)->lock))
#define _UNLOCK(s)		cpu_unlock(&((s)->lock))
#define ALIGN(a,x)		((((unsigned long)a)+(((unsigned long)x)-1)) & (~(((unsigned long)x)-1)))
#define MUL_MAY_OVERFLOW(v)		((v) & 0xFFFF0000)

/* Architecture dependant function --------------------------------------- */
extern void cpu_lock(char* lock);
extern void cpu_unlock(char* lock);
extern void cpu_inc(int* value);
extern void cpu_dec(int* value);


#if defined (__cplusplus) 
}
#endif

#endif
