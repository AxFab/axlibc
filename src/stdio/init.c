#include <prv/stream.h>

int errno;
FILE* stdout;
FILE* stdin;
FILE* stderr;

void stdio_init () 
{
  stdout = fopen ("$stdout", "a");
  stdin = fopen ("$stdin", "r");
  stderr = fopen ("$stderr", "a");
}
