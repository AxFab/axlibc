#ifndef DLFCN_H__
#define DLFCN_H__
#include <sys/version.h>

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

/** When any of the above function fails, this function allow to a 
 * string describing the error
 */
char* dlerror (void);

#endif /* DLFCN_H__ */
