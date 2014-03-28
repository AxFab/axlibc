#ifndef SIGNAL_H__
#define SIGNAL_H__


#define SIGINT     2  /**< Interactive attention signal */
#define SIGILL     4  /**< Illegal instruction */
#define SIGABRT    6  /**< Abnormal termination / abort() */
#define SIGFPE     8  /**< Arithmetic exception: division by zero, overflow */
#define SIGSEGV   11  /**< Invalid memory access */
#define SIGTERM   15  /**< Termination request */


#define SIG_DFL (void (*)( int ))0
#define SIG_ERR (void (*)( int ))-1
#define SIG_IGN (void (*)( int ))1


typedef int sig_atomic_t;



/* Installs a signal handler "func" for the given signal.
   A signal handler is a function that takes an integer as argument (the signal
   number) and returns void.

   Note that a signal handler can do very little else than:
   1) assign a value to a static object of type "volatile sig_atomic_t",
   2) call signal() with the value of sig equal to the signal received,
   3) call _Exit(),
   4) call abort().
   Virtually everything else is undefind.

   The signal() function returns the previous installed signal handler, which
   at program start may be SIG_DFL or SIG_ILL. (This implementation uses
   SIG_DFL for all handlers.) If the request cannot be honored, SIG_ERR is
   returned and errno is set to an unspecified positive value.
*/
void (*signal( int sig, void (*func)( int ) ) )( int );

/* Raises the given signal (executing the registered signal handler with the
   given signal number as parameter).
   This implementation does not prevent further signals of the same time from
   occuring, but executes signal( sig, SIG_DFL ) before entering the signal
   handler (i.e., a second signal before the signal handler re-registers itself
   or SIG_IGN will end the program).
   Returns zero if successful, nonzero otherwise. */
int raise( int sig );




#endif /* SIGNAL_H__ */
