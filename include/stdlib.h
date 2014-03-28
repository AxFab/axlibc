#ifndef STDLIB_H__
#define STDLIB_H__

#include <stddef.h>

__AXLIBC_BEG


#define EXIT_SUCCESS (0)
#define EXIT_FAILURE (-1)


typedef struct div div_t;
typedef struct ldiv ldiv_t;
typedef struct lldiv lldiv_t;

struct div
{
  int quot;
  int rem;
};

struct ldiv
{
  long quot;
  long rem;
};

struct lldiv
{
  long long quot;
  long long rem;
};




void* malloc (size_t size);
void free (void* ptr);

void abort (void);

__AXLIBC_END

#endif /* STDLIB_H__ */
