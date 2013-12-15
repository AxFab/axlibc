#ifndef STDIO_H__
#define STDIO_H__
#include <stddef.h> // EOL, NULL

// ===========================================================================
// Config --------------------------------------------------------------------
#define BUFSIZ  65536 /**< Size of <stdio.h> buffers. */

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

#define stdout  stdout
#define stdin   stdin
#define stderr  stderr


#define O_RDONLY    0x001
#define O_WRONLY    0x002
#define O_RDWR      0x004
#define O_CREAT     0x008
#define O_APPEND    0x010
#define O_DSYNC     0x020
#define O_EXCL      0x040
#define O_NOCTTY    0x080
#define O_NONBLOCK  0x100
#define O_RSYNC     0x200
#define O_SYNC      0x400
#define O_TRUNC     0x800


// ===========================================================================
// Typedef FILE --------------------------------------------------------------
typedef struct axStream FILE;
FILE* stdout;
FILE* stdin;
FILE* stderr;


// ===========================================================================
// Functions prototypes ------------------------------------------------------


// open.c --------------------------------------------------------------------
FILE* fopen (const char* restrict file, const char* restrict mode);
FILE* fdopen (int fd, const char* mode) ;
FILE *freopen (const char *restrict file, const char *restrict mode, FILE *restrict fp);

// int creat(const char *pathname, mode_t mode);
// int open(const char *pathname, int oflags, ...);

/* Read Write Datas */
int      fgetc(FILE *);
char    *fgets(char *restrict, int, FILE *restrict);
int      fputc(int, FILE *);
int      fputs(const char *restrict, FILE *restrict);
size_t   fread(void *restrict, size_t, size_t, FILE *restrict);
int      fscanf(FILE *restrict, const char *restrict, ...);
char    *gets(char *);
int      printf(const char *restrict, ...);
int      putc(int, FILE *);
int      putchar(int);
int      putc_unlocked(int, FILE *);
int      putchar_unlocked(int);
int      puts(const char *);
int      scanf(const char *restrict, ...);
int      snprintf(char *restrict, size_t, const char *restrict, ...);
int      sprintf(char *restrict, const char *restrict, ...);
int      sscanf(const char *restrict, const char *restrict, int ...);
size_t   fwrite(const void *restrict, size_t, size_t, FILE *restrict);
int      fprintf(FILE *restrict, const char *restrict, ...);


int      ungetc(int, FILE *);
int      feof(FILE *);
int      fseek(FILE *, long, int);
int      fseeko(FILE *, off_t, int);
int      fsetpos(FILE *, const fpos_t *);
long     ftell(FILE *);
off_t    ftello(FILE *);
int      fgetpos(FILE *restrict, fpos_t *restrict);


void     flockfile(FILE *);
int      ftrylockfile(FILE *);
void     funlockfile(FILE *);



void     clearerr(FILE *);
char    *ctermid(char *);
int      fclose(FILE *);
int      ferror(FILE *);
int      fflush(FILE *);
int      fileno(FILE *);
int      pclose(FILE *);
void     perror(const char *);
FILE    *popen(const char *, const char *);
int      remove(const char *);
int      rename(const char *, const char *);
void     rewind(FILE *);
void     setbuf(FILE *restrict, char *restrict);
int      setvbuf(FILE *restrict, char *restrict, int, size_t);
char    *tempnam(const char *, const char *);
FILE    *tmpfile(void);
char    *tmpnam(char *);


int      vfprintf(FILE *restrict, const char *restrict, va_list);
int      vfscanf(FILE *restrict, const char *restrict, va_list);
int      vprintf(const char *restrict, va_list);
int      vscanf(const char *restrict, va_list);
int      vsnprintf(char *restrict, size_t, const char *restrict, va_list);
int      vsprintf(char *restrict, const char *restrict, va_list);
int      vsscanf(const char *restrict, const char *restrict, va_list arg);




#endif /* STDIO_H__ */
