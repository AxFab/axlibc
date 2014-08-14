#ifndef AX_FILE_H__
#define AX_FILE_H__

#include <ax/core.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>

#ifdef _C89
# define FLOCK(fp)   int __need_unlock = ((fp)->lock_ >= 0 ? __lockfile(fp) : 0)
# define FUNLOCK(fp) do { if (__need_unlock) __unlockfile(fp); } while(0)
#else
# define FLOCK(fp)
# define FUNLOCK(fp)
#endif

#define OF_EOF    0x1000
#define OF_ERR    0x2000
#define OF_RIGHTS  0644

typedef  struct axFormatSpec axFormatSpec_t;
typedef union axArg axArg_t;

struct axFormatSpec
{
  int   flag_;
  int   field_;
  int   precis_;
  int   type_;
};

union axArg
{
  intmax_t s;
  uintmax_t i;
  long double f;
  void *p;
};


extern FILE* OFP_HEAD;

struct axFile
{
  int     fd_;
  int     oflags_;
  FILE*   next_;

  int     lock_;
  int     count_;
  char    lbuf_;

  char*   buf_;
  off_t   off_;
  off_t   lpos_;
  size_t  bsize_;

  char*   rpos_;
  char*   rend_;

  char*   wpos_;
  char*   wend_;

  int (*write_) (FILE *restrict fp, const char* restrict buf, size_t length);
  int (*read_) (FILE *restrict fp, char* restrict buf, size_t length);
};

int _dwrite (FILE *restrict fp, const char* restrict buf, size_t length);
int _fwrite (FILE *restrict fp, const char* restrict buf, size_t length);
int _dread (FILE *restrict fp, const char* restrict buf, size_t length);
int _fread (FILE *restrict fp, const char* restrict buf, size_t length);

void flockfile (FILE* restrict stream);
void funlockfile (FILE* restrict stream);
int ftrylockfile (FILE* restrict stream);


int fflush_unlocked (FILE* restrict stream);
int fill_cache (FILE* stream);
int flush_cache (FILE* stream);




int vfprintf(FILE *restrict fp, const char *restrict format, va_list ap);
int vfscanf(FILE *restrict f, const char *restrict format, va_list ap);


#endif /* AX_FILE_H__ */
