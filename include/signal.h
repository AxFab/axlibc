#ifndef SIGNAL_H__
#define SIGNAL_H__

/** @file signal.h
 * @brief signal management 
 * @version C89, C99, IEEE, Unix95, Unix98, POSIX, XSI
 * 
 * The <signal.h> header defines the following symbolic constants, each of 
 * which expands to a distinct constant expression of the type: void (*)(int)
 * The following data types are defined through typedef
 * The <signal.h> header defines the sigevent structure and sigval union.
 */

#include <features.h>

__AXLIBC_BEG

/** No asynchronous notification will be delivered when the event of interest 
 * occurs. */
#define SIGEV_NONE

/** A queued signal, with an application-defined value, will be generated when 
 * the event of interest occurs. */
#define SIGEV_SIGNAL

/** A notification function will be called to perform notification. */
#define SIGEV_THREAD


// ---------------------------------------------------------------------------
#define  SIGHUP      1  /**< Hangup. */  
#define  SIGINT      2  /**< Terminal interrupt signal. */  
#define  SIGQUIT     3  /**< Terminal quit signal. */  
#define  SIGILL      4  /**< Illegal instruction. */  
#define  SIGABRT     6  /**< Process abort signal. */  
#define  SIGFPE      8  /**< Erroneous arithmetic operation. */  
#define  SIGKILL     9  /**< Kill (cannot be caught or ignored). */  
#define  SIGSEGV    11  /**< Invalid memory reference. */  
#define  SIGPIPE    13  /**< Write on a pipe with no one to read it. */  
#define  SIGALRM    14  /**< Alarm clock. */  
#define  SIGTERM    15  /**< Termination signal. */  
#define  SIGSTOP    17  /**< Stop executing (cannot be caught or ignored). */  
#define  SIGTSTP    18  /**< Terminal stop signal. */  
#define  SIGCONT    19  /**< Continue executing, if stopped. */  
#define  SIGCHLD    20  /**< Child process terminated or stopped. */  
#define  SIGTTIN    21  /**< Background process attempting read. */  
#define  SIGTTOU    22  /**< Background process attempting write. */  
#define  SIGUSR1    30  /**< User-defined signal 1. */  
#define  SIGUSR2    31  /**< User-defined signal 2. */  

// ---------------------------------------------------------------------------
#define  SIGTRAP     5  /**< Trace/breakpoint trap. */  
#define  SIGBUS     10  /**< Access to an undefined portion of a memory object. */  
#define  SIGPOLL    10  /**< Pollable event. */  
#define  SIGSYS     12  /**< Bad system call. */  
#define  SIGURG     16  /**< High bandwidth data is available at a socket. */
#define  SIGXCPU    24  /**< CPU time limit exceeded. */  
#define  SIGXFSZ    25  /**< File size limit exceeded. */    
#define  SIGVTALRM  26  /**< Virtual timer expired. */  
#define  SIGPROF    27  /**< Profiling timer expired. */  

// ---------------------------------------------------------------------------
#define  SIGIOT      6  /**< IOT trap. A synonym for SIGABRT */  
#define  SIGEMT      7  /**<  */  
#define  SIGIO      23  /**< I/O now possible  */  
#define  SIGWINCH   28  /**< Window resize signal (4.3BSD, Sun) */  
#define  SIGPWR     29  /**< Power failure */  

// ---------------------------------------------------------------------------
#define SIG_DFL   (&_sig_dfl)   /**< Request for default signal handling. */
#define SIG_ERR   (&_sig_err)   /**< Return value from signal() in case of error. */
#define SIG_HOLD  (&_sig_hold)  /**< Request that signal be held. */
#define SIG_IGN   (&_sig_ign)   /**< Request that signal be ignored. */


// ===========================================================================
typedef int sig_atomic_t;
typedef int sigset_t;
typedef int pid_t;
typedef int siginfo_t;


typedef union sigval 
{
  int    sival_int;    /**< integer signal value */
  void*  sival_ptr;    /**< pointer signal value */
};


typedef struct sigevent 
{
  int                      sigev_notify;          /**< notification type */
  int                      sigev_signo;           /**< signal number */
  union sigval             sigev_value;            /**< signal value */
  void(*sigev_notify_function)(union sigval)    ;   /**< notification function */
  // (pthread_attr_t*)        sigev_notify_attributes; /**< notification attributes */
};



typedef struct sigaction
{
  void     (*sa_handler)(int);  /** what to do on receipt of signal */
  sigset_t   sa_mask;           /** set of signals to be blocked during execution of the signal handling function */
  int        sa_flags;          /** special flags */
  void (*sa_sigaction)(int, siginfo_t *, void *) ; /**< pointer to signal handler function or one of the macros SIG_IGN or SIG_DFL */
};

// ===========================================================================+

struct sigaction sa_handler;
struct sigaction sa_sigaction;


void _sig_dfl (int);
void _sig_err (int);
void _sig_hold (int);
void _sig_ign (int);


/*
  Installs a signal handler "func" for the given signal.
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

/* 
  Raises the given signal (executing the registered signal handler with the
  given signal number as parameter).
  This implementation does not prevent further signals of the same time from
  occuring, but executes signal( sig, SIG_DFL ) before entering the signal
  handler (i.e., a second signal before the signal handler re-registers itself
  or SIG_IGN will end the program).
  Returns zero if successful, nonzero otherwise. 
 */
int raise( int sig );


void (*bsd_signal(int, void (*)(int)))(int);
int    kill(pid_t, int);
int    killpg(pid_t, int);
//int    pthread_kill(pthread_t, int);
// int    pthread_sigmask(int, const sigset_t *, sigset_t *);
// int    raise(int);
int    sigaction(int, const struct sigaction *, struct sigaction *);
int    sigaddset(sigset_t *, int);
// int    sigaltstack(const stack_t *, stack_t *);
int    sigdelset(sigset_t *, int);
int    sigemptyset(sigset_t *);
int    sigfillset(sigset_t *);
int    sighold(int);
int    sigignore(int);
int    siginterrupt(int, int);
int    sigismember(const sigset_t *, int);
// void (*signal(int, void (*)(int)))(int);
int    sigpause(int);
int    sigpending(sigset_t *);
int    sigprocmask(int, const sigset_t *, sigset_t *);
int    sigqueue(pid_t, int, const union sigval);
int    sigrelse(int);
void (*sigset(int, void (*)(int)))(int);
// int    sigstack(struct sigstack *ss, struct sigstack *oss); (LEGACY)
int    sigsuspend(const sigset_t *);
int    sigtimedwait(const sigset_t *, siginfo_t *,
           const struct timespec *);
int    sigwait(const sigset_t *set, int *sig);
int    sigwaitinfo(const sigset_t *, siginfo_t *);




__AXLIBC_END

#endif /* SIGNAL_H__ */
