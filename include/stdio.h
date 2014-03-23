#ifndef STDIO_H__
#define STDIO_H__
/* ISO C99 Standard: 7.19 Input/output  <stdio.h> */
#include <stddef.h>
#include <stdarg.h>
#include <limits.h>

/* ======================================================================== */
#define _IOFBF    1           /**< Fully buffered.  */
#define _IOLBF    2           /**< Line buffered.  */
#define _IONBF    3           /**< No buffering.  */

#define EOF       (-1)        /**< End of file character. */
#define BUFSIZ    512         /**< File buffer size */

#define SEEK_SET  0           /**< Seek from beginning of file.  */
#define SEEK_CUR  1           /**< Seek from current position.  */
#define SEEK_END  2           /**< Seek from end of file.  */

#define P_tmpdir  "/tmp"      /**< Default path prefix for 'mkstemp'. */

/* C89/C99 say they're macros. */
#define stdin stdin
#define stdout stdout
#define stderr stderr


/* ======================================================================== */
typedef struct Stream_t FILE; /**< File opaque pointer */ 

/* Standard streams.  */
extern FILE *stdin;           /**< Standard input stream.  */
extern FILE *stdout;          /**< Standard output stream.  */
extern FILE *stderr;          /**< Standard error output stream.  */

/* ======================================================================== */

/* access.c --------------------------------------------------------------- */
int      fclose(FILE *fp);
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
void    clearerr(FILE *fp);
int     feof(FILE *fp);
int     ferror(FILE *);
int     fileno(FILE *fp);
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
int      fseeko(FILE *, off_t, int);
int      fsetpos(FILE *, const fpos_t *);
long int ftell(FILE *);
off_t    ftello(FILE *);
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
#define feof(fp)          ((fp)->_eof)
#define ferror(fp)        ((fp)->_err)
#define clearerr(fp)      ((fp)->_err = (fp)->_eof = 0)
#define fileno(fp)        ((fp)->_fd)

/* Replace by what !?
#define getc(fp)          
#define getchar()
#define putc(c,fp)
#define putchar(c)
*/

#endif /* STDIO_H__ */
