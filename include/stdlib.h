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

div_t div (int, int);
ldiv_t ldiv (long, long);
lldiv_t lldiv (long long, long long);

int abs (int value);



int atoi (const char* str);
long atol (const char* str);
long long atoll (const char* str);

long strtol (const char * str, char ** endptr, int base);
long long strtoll (const char * str, char ** endptr, int base);
unsigned long strtoul (const char * str, char ** endptr, int base);
unsigned long long strtoull (const char * str, char ** endptr, int base);

char* itoa (int value, char* str, int base);



void* malloc (size_t size);
void free (void* ptr);

void abort (void);

__AXLIBC_END

#endif /* STDLIB_H__ */
