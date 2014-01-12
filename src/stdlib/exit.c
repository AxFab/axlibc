#include <stddef.h> // size_t
#include <stdlib.h> // _exit
#include <signal.h> // raise, SIGABRT

#define ATEXIT_STACK_SIZE 32

// ---------------------------------------------------------------------------
/** stack array for at-exit functions */
void (*_atexitStack[ATEXIT_STACK_SIZE])(void);

/** stack pointer for at-exit functions */
size_t _atexitPtr = ATEXIT_STACK_SIZE;

// ---------------------------------------------------------------------------
/** register a function to launch at the end of process */
int atexit( void (*func)( void ) )
{
  if (_atexitPtr == 0) {
    return -1;
  }

  _atexitStack[ --_atexitPtr ] = func;
  return 0;
}

// ---------------------------------------------------------------------------
/** launch the regular routines for a program to exit */
void exit (int status)
{
  while (_atexitPtr < ATEXIT_STACK_SIZE)
  {
      _atexitStack[_atexitPtr++]();
  }

  _exit(status);
}

// ---------------------------------------------------------------------------
/** rasie the signal SIGABRT and terminate the program with the failure code */
void abort (void)
{
  raise(SIGABRT);
  exit(EXIT_FAILURE);
}

