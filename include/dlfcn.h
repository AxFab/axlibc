#ifndef DLFCN_H__
#define DLFCN_H__

/** @file dlfcn.h
 * @brief dynamic linking 
 * 
 * The <dlfcn.h> header defines at least macros for use in the construction
 * of a dlopen() mode argument.
 * The header <dlfcn.h> declares the following functions which may also be 
 * defined as macros. Function prototypes must be provided for use with an 
 * ISO C compiler. 
 */

#include <features.h>

__AXLIBC_BEG

/** Relocations are performed at an implementation-dependent time. */
#define RTLD_LAZY   

/** Relocations are performed when the object is loaded. */
#define RTLD_NOW

/** All symbols are available for relocation processing of other modules. */
#define RTLD_GLOBAL 

/** All symbols are not made available for relocation processing by other 
 * modules. */
#define RTLD_LOCAL  


/** Open the shared object FILE and map it in.
 * @return A handle that can be passed to 'dlsym' to get symbol values from it.
 */
void* dlopen (const char* library, int mode);

/** Unmap and close a shared object opened by 'dlopen'
 */
void dlclose (void* library);

/** Find the run-time address of the symbol called by name 
 */
void* dlsym (void* library, const char* name);

/** When any of the above function fails, this function allow to retrieve a 
 * string describing the error
 */
char* dlerror (void);

__AXLIBC_END

#endif /* DLFCN_H__ */
