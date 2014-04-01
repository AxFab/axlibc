#ifndef STDIO_H__
#define STDIO_H__

/** @file stdio.h
 * @brief standard buffered input/output 
 * @version C89, C99, IEEE, Unix95, Unix98, POSIX, XSI
 * 
 * The <stdio.h> header defines the following
 */

#include <stddef.h>
#include <stdarg.h>
#include <limits.h>

__AXLIBC_BEG

// ===========================================================================
// Config --------------------------------------------------------------------
#define BUFSIZ  65536 /**< Size of <stdio.h> buffers. */

/** Maximum size in bytes of the longest filename string that the 
 * implementation guarantees can be opened. */
#define FILENAME_MAX 260


#define FOPEN_MAX 20
#define TMP_MAX 32767

// ===========================================================================
// Constants -----------------------------------------------------------------
#define _IOFBF 0x1 /**< Input/output fully buffered. */
#define _IOLBF 0x2 /**< Input/output line buffered. */
#define _IONBF 0x4 /**< Input/output unbuffered. */

#define SEEK_SET 0 /**< Seek relative to start-of-file. */
#define SEEK_CUR 1 /**< Seek relative to current position. */
#define SEEK_END 2 /**< Seek relative to end-of-file. */

/* C89/C99 say they're macros. */
#define stdout  stdout
#define stdin   stdin
#define stderr  stderr



#define EOF       (-1)        /**< End of file character. */
#define EOL       "\n"        /**< End of line character. */

#define P_tmpdir  "/tmp"      /**< Default path prefix for 'mkstemp'. */



// ===========================================================================
// Typedef FILE --------------------------------------------------------------
typedef struct axStream FILE;

/* Standard streams.  */
extern FILE *stdout;          /**< Standard output stream.  */
extern FILE *stdin;           /**< Standard input stream.  */
extern FILE *stderr;          /**< Standard error output stream.  */






// ===========================================================================
// Functions prototypes - close.c---------------------------------------------
void clearerr (FILE* stream);
int feof (FILE* stream);
int ferror (FILE* stream);
int fclose (FILE* stream);
int fileno (FILE* stream);


/* access.c --------------------------------------------------------------- */
FILE    *fdopen(int, const char *);
FILE    *fopen(const char *, const char *);
FILE    *freopen(const char *, const char *, FILE *);

int      fflush(FILE *);

void     flockfile(FILE *);
int      ftrylockfile(FILE *);
void     funlockfile(FILE *);

void     setbuf(FILE *, char *);
int      setvbuf(FILE *, char *, int, size_t);

/* data.c ----------------------------------------------------------------- */
size_t   fread(void *, size_t, size_t, FILE *);
size_t   fwrite(const void *, size_t, size_t, FILE *);
int      getc_unlocked(FILE *);
int      getchar_unlocked(void);
int      putc_unlocked(int, FILE *);
int      putchar_unlocked(int);
int      ungetc(int, FILE *);

/* format.c --------------------------------------------------------------- */
int      fprintf(FILE *, const char *, ...);
int      fscanf(FILE *, const char *, ...);
int      printf(const char *, ...);
int      scanf(const char *, ...);
int      vfprintf(FILE *, const char *, va_list);
int      vprintf(const char *, va_list);
int      vsnprintf(char *, size_t, const char *, va_list);
int      vsprintf(char *, const char *, va_list);
int      snprintf(char *, size_t, const char *, ...);
int      sprintf(char *, const char *, ...);
int      sscanf(const char *, const char *, ...);

/* info.c ----------------------------------------------------------------- */

char   *tempnam(const char *, const char *);
FILE   *tmpfile(void);
char   *tmpnam(char *);

/* link.c ----------------------------------------------------------------- */
int      remove(const char *);
int      rename(const char *, const char *);

/* process.c -------------------------------------------------------------- */
int      pclose(FILE *);
void     perror(const char *);
FILE    *popen(const char *, const char *);

/* seek.c ----------------------------------------------------------------- */
int      fgetpos(FILE *, fpos_t *);
int      fseek(FILE *, long int, int);
// int      fseeko(FILE *, off_t, int);
int      fsetpos(FILE *, const fpos_t *);
long int ftell(FILE *);
// off_t    ftello(FILE *);
void     rewind(FILE *);

/* string.c --------------------------------------------------------------- */
int      fgetc(FILE *);
char    *fgets(char *, int, FILE *);
int      fputc(int, FILE *);
int      fputs(const char *, FILE *);
int      getc(FILE *);
int      getchar(void);
char    *gets(char *);
int      getw(FILE *);
int      putc(int, FILE *);
int      putchar(int);
int      puts(const char *);
int      putw(int, FILE *);

/* tty.c ------------------------------------------------------------------ */
char    *ctermid(char *);
char    *cuserid(char *);


/* ======================================================================== */
/* option.c --------------------------------------------------------------- */
int      getopt(int argc, char * const argv[], const char *optstring);
extern char *optarg;
extern int optind, opterr, optopt;


/* ======================================================================== */

/* Replace by what !?
#define getc(fp)          
#define getchar()
#define putc(c,fp)
#define putchar(c)
*/
__AXLIBC_END

#endif /* STDIO_H__ */
