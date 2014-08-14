#include <stdio.h>
#include <unistd.h>

FILE* stdout;
FILE* stdin;
FILE* stderr;

void stdio_init ()
{
  stdin = fdopen (STDIN_FILENO, "r");
  stdout = fdopen (STDOUT_FILENO, "a");
  stderr = fdopen (STDERR_FILENO, "a");
}
