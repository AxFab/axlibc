#ifndef STRING_H__
#define STRING_H__
/** ISO C99 Standard: 7.21 String handling	<string.h> */

/* ----------------------------------------------------------------------- */
#include <stddef.h>

#if defined(__AX) || defined(__C99)
#include <stdint.h>
#endif

__AXLIBC_BEG

/* ----- memory.c -------------------------------------------------------- */
void* memcpy (void* restrict dest, const void* restrict src, size_t length);
void* memmove (void* dest, const void* src, size_t length);
int memcmp (const void* dest, const void* src, size_t length);
void* memchr (const void* ptr, int chr, size_t length);
void* memset (void* ptr, int val, size_t length);

#if defined(__BSD)
void* memccpy (void* restrict dest, const void* restrict src, int c, size_t length);
#endif 

#if defined(__GNU)
void* rawmemchr (const void* ptr, int chr);
void *memrchr (const void* ptr, int chr, size_t length);
void *mempcpy (void* restrict dest, const void* restrict src, size_t length);
void* memmem (const void* haystack, size_t haystacklen, const void* needle, size_t needlelen);
#endif

/* ----- string.c -------------------------------------------------------- */
char* strcpy (char* restrict dest, const char* restrict src);
char* strncpy (char* restrict dest, const char* restrict src, size_t length);
char* strcat (char* restrict dest, const char* restrict src);
char* strncat (char* restrict dest, const char* restrict src, size_t length);
int strcmp (const char* str1, const char* str2);
int strncmp (const char* str1, const char* str2, size_t length);
int strcoll (char* str1, const char* str2);
size_t strxfrm (char* restrict dest, const char* restrict src, size_t length);

#if defined __USE_XOPEN2K8 && defined __UCLIBC_HAS_XLOCALE__
int strcoll_l (const char* str1, const char* str2, __locale_t locale);
size_t strxfrm_l (char* restrict dest, const char* restrict src, size_t length, __locale_t locale);
#endif

#if defined __USE_SVID || defined __USE_BSD || defined __USE_XOPEN_EXTENDED
char* strdup (const char* str);
#endif

#if defined __USE_XOPEN2K8
char* strndup (const char* str, size_t length);
#endif


/* ----- text.c ---------------------------------------------------------- */
char* strchr (const char* string, int ch);
char* strnchr (const char* string, int length, int ch);
char* strrchr (const char* string, int ch);
char* strtok (char* restrict string, const char* restrict delimitors);
size_t strcspn (const char* string, const char* reject);
size_t strspn (const char* string, const char* accept);
char* strpbrk (const char* string, const char* accept);
char* strstr (const char* haystack, const char* needle);
size_t strlen (const char* string);

#if defined(__U95) || defined(__EX)
char* strtok_r (char* restrict string, const char* restrict delim, char **save);
#endif

#ifdef __USE_GNU
char* strchrnul (const char* string, int ch);
char* strcasestr  (const char* haystack, const char* needle);
#endif

#ifdef	__USE_XOPEN2K8
size_t strnlen (const char* string, size_t maxlen);
#endif

/* ----- error.c --------------------------------------------------------- */
char* strerror (int err);

#if defined __USE_XOPEN2K || defined __USE_MISC
int strerror_r (int err, char* buffer, size_t length);
#endif

#if defined (__LOCAL)
char* strerror_l (int err, __locale_t locale);
#endif

/* ----------------------------------------------------------------------- */
/* ----------------------------------------------------------------------- */
#if defined (__BSD)
# define bcopy(src,dest,n) (memmove((dest), (src), (n)), (void) 0)
# define bzero(s,n) (memset((s), '\0', (n)), (void) 0)
# define bcmp(s1,s2,n) memcmp((s1), (s2), (size_t)(n))
# define index(s,c) strchr((s), (c))
# define rindex(s,c) strrchr((s), (c))

char* strsep (char** restrict stringp, const char* restrict delim);
int strcasecmp (const char* str1, const char* str2);
int strncasecmp (const char* str1, const char* str2, size_t length);
int ffs (int integer);
#ifdef __USE_GNU
int ffsl (long int integer);
# endif
#endif

#if defined __USE_XOPEN2K8 && defined __LIBC_HAS_XLOCALE__
int strcasecmp_l (const char* str1, const char* str2, __locale_t local);
int strncasecmp_l (const char* str1, const char* str2, size_t length, __locale_t local);
#endif

#ifdef	__USE_XOPEN2K8
char* strsignal (int signal);
char *stpcpy (char* restrict dest, const char* restrict src);
char *stpncpy (char* restrict  dest, const char* restrict src, size_t length);
#endif

#ifdef __USE_GNU
extern int strverscmp (const char* str1, const char* str2);
#endif

#ifdef	__USE_BSD
size_t strlcat(char *restrict dst, const char *restrict src, size_t length);
size_t strlcpy(char *restrict dst, const char *restrict src, size_t length);
#endif


#if defined(__AX) || defined(__EX)
// TODO Always for compilation
int bpw2 (unsigned long v);
int bsetbyte (uint8_t* byte, int off, int lg);
int bclearbyte (uint8_t* byte, int off, int lg);
int bsetbytes (uint8_t* table, int offset, int length);
int bclearbytes (uint8_t* table, int offset, int length);

#endif

/* ----------------------------------------------------------------------- */

__AXLIBC_END

#endif /* STRING_H_ */
