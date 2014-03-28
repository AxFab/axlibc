#ifndef LIMITS_H__
#define LIMITS_H__

#include <features.h>
#include <datamodel.h>

// ===========================================================================
// Define limits for integer size

#define MB_LEN_MAX      16                      //< Maximum length of any multibyte character in any locale. */
#define CHAR_BIT        __CHAR_BITS             //< Number of bits in a 'char'.
#define LONG_BIT        __LONG_BITS             //< Number of bits in a 'long'.
#define WORD_BIT        16                      //< Number of bits in a 'word'.

#define SCHAR_MIN       (-128)                  //< Minimum values a 'signed char' can hold.
#define SCHAR_MAX       127                     //< Maximum values a 'signed char' can hold.
#define UCHAR_MAX       255                     //< Maximum value an 'unsigned char' can hold. (Minimum is 0.)
#define CHAR_MIN        SCHAR_MIN               //< Minimum values a 'char' can hold.
#define CHAR_MAX        SCHAR_MAX               //< Maximum values a 'char' can hold.
#define SHRT_MIN        (-32768)                //< Minimum values a 'signed short int' can hold.
#define SHRT_MAX        32767                   //< Maximum values a 'signed short int' can hold.
#define USHRT_MAX       65535                   //< Maximum value an 'unsigned short int' can hold.  (Minimum is 0.)
#define INT_MIN         (-INT_MAX - 1)          //< Minimum and maximum values a 'signed int' can hold.
#define INT_MAX         2147483647              //< Minimum and maximum values a 'signed int' can hold.
#define UINT_MAX        4294967295U             //< Maximum value an 'unsigned int' can hold.  (Minimum is 0.)
#define LONG_MAX        2147483647L             //< Maximum values a 'signed long int' can hold.
#define LONG_MIN        (-LONG_MAX - 1L)        //< Minimum values a 'signed long int' can hold.
#define ULONG_MAX       4294967295UL            //< Maximum value an 'unsigned long int' can hold.  (Minimum is 0.)
#define LLONG_MAX       9223372036854775807LL   //< Maximum values a 'signed long long int' can hold.
#define LLONG_MIN       (-LLONG_MAX - 1LL)      //< Minimum values a 'signed long long int' can hold.
#define ULLONG_MAX      18446744073709551615ULL //< Maximum value an 'unsigned long long int' can hold.  (Minimum is 0.)

/* ===========================================================================
			POSIX Defined Values
=========================================================================== */
#define _POSIX_AIO_LISTIO_MAX   2               /*< The number of I/O operations that can be specified in a list I/O call. */
#define _POSIX_AIO_MAX          1               /*< The number of outstanding asynchronous I/O operations. */
#define _POSIX_ARG_MAX          4096            /*< Maximum length of argument to the exec functions including environment data. */
#define _POSIX_CHILD_MAX        25              /*< Maximum number of simultaneous processes per real user ID. */
#define _POSIX_DELAYTIMER_MAX   32              /*< The number of timer expiration overruns. */
#define _POSIX_HOST_NAME_MAX    255             /*< Maximum length of a host name (not including the terminating null) as returned from the gethostname() function. */
#define _POSIX_LINK_MAX         8               /*< Maximum number of links to a single file. */
#define _POSIX_LOGIN_NAME_MAX   9               /*< The size of the storage required for a login name, in bytes, including the terminating null. */
#define _POSIX_MAX_CANON        255             /*< Maximum number of bytes in a terminal canonical input queue. */
#define _POSIX_MAX_INPUT        255             /*< Maximum number of bytes allowed in a terminal input queue. */
#define _POSIX_MQ_OPEN_MAX      8               /*< The number of message queues that can be open for a single process. */
#define _POSIX_MQ_PRIO_MAX      32              /*< The maximum number of message priorities supported by the implementation. */
#define _POSIX_NAME_MAX         14              /*< Maximum number of bytes in a filename (not including terminating null). */
#define _POSIX_NGROUPS_MAX      8               /*< Maximum number of simultaneous supplementary group IDs per process. */
#define _POSIX_OPEN_MAX         20              /*< Maximum number of files that one process can have open at any one time. */
#define _POSIX_PATH_MAX         256             /*< Maximum number of bytes in a pathname. */
#define _POSIX_PIPE_BUF         512             /*< Maximum number of bytes that is guaranteed to be atomic when writing to a pipe. */
#define _POSIX_RE_DUP_MAX       255             /*< The number of repeated occurrences of a BRE permitted by the regexec() and regcomp() functions when using the interval notation {\(m,n\}; see BREs Matching Multiple Characters . */
#define _POSIX_RTSIG_MAX        8               /*< he number of realtime signal numbers reserved for application use. */
#define _POSIX_SEM_NSEMS_MAX    256             /*< The number of semaphores that a process may have. */
#define _POSIX_SEM_VALUE_MAX    32767           /*< The maximum value a semaphore may have. */
#define _POSIX_SIGQUEUE_MAX     32              /*< The number of queued signals that a process may send and have pending at the receiver(s) at any time. */
#define _POSIX_SSIZE_MAX        32767           /*< The value that can be stored in an object of type ssize_t. */
#define _POSIX_STREAM_MAX       8               /*< The number of streams that one process can have open at one time. */
#define _POSIX_SS_REPL_MAX      4               /*< The number of replenishment operations that may be simultaneously pending for a particular sporadic server scheduler. */
#define _POSIX_SYMLINK_MAX      255             /*< The number of bytes in a symbolic link. */
#define _POSIX_SYMLOOP_MAX      8               /*< The number of symbolic links that can be traversed in the resolution of a pathname in the absence of a loop. */
#define _POSIX_THREAD_DESTRUCTOR_ITERATIONS 4   /*< The number of attempts made to destroy a thread's thread-specific data values on thread exit. */
#define _POSIX_THREAD_KEYS_MAX  128             /*< The number of data keys per process. */
#define _POSIX_THREAD_THREADS_MAX 64            /*< The number of threads per process. */
#define _POSIX_TIMER_MAX        32              /*< The per-process number of timers. */
#define _POSIX_TRACE_EVENT_NAME_MAX 30          /*< The length in bytes of a trace event name. */
#define _POSIX_TRACE_NAME_MAX   8               /*< The length in bytes of a trace generation version string or a trace stream name. */
#define _POSIX_TRACE_SYS_MAX    8               /*< The number of trace streams that may simultaneously exist in the system. */
#define _POSIX_TRACE_USER_EVENT_MAX 32          /*< The number of user trace event type identifiers that may simultaneously exist in a traced process, including the predefined user trace event POSIX_TRACE_UNNAMED_USER_EVENT. */
#define _POSIX_TTY_NAME_MAX     9               /*< The size of the storage required for a terminal device name, in bytes, including the terminating null. */
#define _POSIX_TZNAME_MAX       6               /*< Maximum number of bytes supported for the name of a timezone (not of the TZ variable). */
/* _POSIX_TZNAME_MAX - Note: The length given by {_POSIX_TZNAME_MAX} does not include the quoting characters mentioned in Other Environment Variables . */
#define _POSIX2_BC_BASE_MAX     99              /*< Maximum obase values allowed by the bc utility. */
#define _POSIX2_BC_DIM_MAX      2048            /*< Maximum number of elements permitted in an array by the bc utility. */
#define _POSIX2_BC_SCALE_MAX    99              /*< Maximum scale value allowed by the bc utility. */
#define _POSIX2_BC_STRING_MAX   1000            /*< Maximum length of a string constant accepted by the bc utility. */
#define _POSIX2_CHARCLASS_NAME_MAX 14           /*< Maximum number of bytes in a character class name. */
#define _POSIX2_COLL_WEIGHTS_MAX 2              /*< Maximum number of weights that can be assigned to an entry of the LC_COLLATE order keyword in the locale definition file; see Locale. */
#define _POSIX2_EXPR_NEST_MAX   32              /*< Maximum number of expressions that can be nested within parentheses by the expr utility. */
#define _POSIX2_LINE_MAX        2048            /*< Unless otherwise noted, the maximum length, in bytes, of a utility's input line (either standard input or another file), when the utility is described as processing text files. The length includes room for the trailing <newline>. */
#define _POSIX2_RE_DUP_MAX      255             /*< Maximum number of repeated occurrences of a regular expression permitted when using the interval notation \{m,n\}; see Regular Expressions . */
#define _XOPEN_IOV_MAX          16              /*< Maximum number of iovec structures that one process has available for use with readv() or writev(). */
#define _XOPEN_NAME_MAX         255             /*< Maximum number of bytes in a filename (not including the terminating null). */
#define _XOPEN_PATH_MAX         1024            /*< Maximum number of bytes in a pathname. */


/* ===========================================================================
			Implementation Defined Values
=========================================================================== */
#define AIO_LISTIO_MAX          _POSIX_AIO_LISTIO_MAX       /*< The number of I/O operations that can be specified in a list I/O call.  */
#define AIO_MAX                 _POSIX_AIO_MAX              /*< The number of outstanding asynchronous I/O operations.  */
#define ARG_MAX                 _POSIX_ARG_MAX              /*< Maximum length of argument to the exec functions including environment data.  */
#define CHILD_MAX               _POSIX_CHILD_MAX            /*< Maximum number of simultaneous processes per real user ID.  */
#define DELAYTIMER_MAX          _POSIX_DELAYTIMER_MAX       /*< The number of timer expiration overruns.  */
#define HOST_NAME_MAX           _POSIX_HOST_NAME_MAX        /*< Maximum length of a host name (not including the terminating null) as returned from the gethostname() function.  */
#define LINK_MAX                _POSIX_LINK_MAX             /*< Maximum number of links to a single file.  */
#define LOGIN_NAME_MAX          _POSIX_LOGIN_NAME_MAX       /*< The size of the storage required for a login name, in bytes, including the terminating null.  */
#define MAX_CANON               _POSIX_MAX_CANON            /*< Maximum number of bytes in a terminal canonical input queue.  */
#define MAX_INPUT               _POSIX_MAX_INPUT            /*< Maximum number of bytes allowed in a terminal input queue.  */
#define MQ_OPEN_MAX             _POSIX_MQ_OPEN_MAX          /*< The number of message queues that can be open for a single process.  */
#define MQ_PRIO_MAX             _POSIX_MQ_PRIO_MAX          /*< The maximum number of message priorities supported by the implementation.  */
#define NAME_MAX                _POSIX_NAME_MAX             /*< Maximum number of bytes in a filename (not including terminating null).  */
#define NGROUPS_MAX             _POSIX_NGROUPS_MAX          /*< Maximum number of simultaneous supplementary group IDs per process.  */
#define OPEN_MAX                _POSIX_OPEN_MAX             /*< Maximum number of files that one process can have open at any one time.  */
#define PATH_MAX                _POSIX_PATH_MAX             /*< Maximum number of bytes in a pathname.  */
#define PIPE_BUF                _POSIX_PIPE_BUF             /*< Maximum number of bytes that is guaranteed to be atomic when writing to a pipe.  */
// #define RE_DUP_MAX              _POSIX_RE_DUP_MAX           /*< The number of repeated occurrences of a BRE permitted by the regexec() and regcomp() functions when using the interval notation {\(m,n\}; see BREs Matching Multiple Characters .  */
#define RTSIG_MAX               _POSIX_RTSIG_MAX            /*< he number of realtime signal numbers reserved for application use.  */
#define SEM_NSEMS_MAX           _POSIX_SEM_NSEMS_MAX        /*< The number of semaphores that a process may have.  */
#define SEM_VALUE_MAX           _POSIX_SEM_VALUE_MAX        /*< The maximum value a semaphore may have.  */
#define SIGQUEUE_MAX            _POSIX_SIGQUEUE_MAX         /*< The number of queued signals that a process may send and have pending at the receiver(s) at any time.  */
#define SSIZE_MAX               _POSIX_SSIZE_MAX            /*< The value that can be stored in an object of type ssize_t.  */
#define STREAM_MAX              _POSIX_STREAM_MAX           /*< The number of streams that one process can have open at one time.  */
#define SS_REPL_MAX             _POSIX_SS_REPL_MAX          /*< The number of replenishment operations that may be simultaneously pending for a particular sporadic server scheduler.  */
#define SYMLINK_MAX             _POSIX_SYMLINK_MAX          /*< The number of bytes in a symbolic link.  */
#define SYMLOOP_MAX             _POSIX_SYMLOOP_MAX          /*< The number of symbolic links that can be traversed in the resolution of a pathname in the absence of a loop.  */
#define THREAD_DESTRUCTOR_ITERATIONS _POSIX_THREAD_DESTRUCTOR_ITERATIONS  /*< The number of attempts made to destroy a thread's thread-specific data values on thread exit.  */
#define THREAD_KEYS_MAX         _POSIX_THREAD_KEYS_MAX      /*< The number of data keys per process.  */
#define THREAD_THREADS_MAX      _POSIX_THREAD_THREADS_MAX   /*< The number of threads per process.  */
#define TIMER_MAX               _POSIX_TIMER_MAX            /*< The per-process number of timers.  */
#define TRACE_EVENT_NAME_MAX    _POSIX_TRACE_EVENT_NAME_MAX /*< The length in bytes of a trace event name.  */
#define TRACE_NAME_MAX          _POSIX_TRACE_NAME_MAX       /*< The length in bytes of a trace generation version string or a trace stream name.  */
#define TRACE_SYS_MAX           _POSIX_TRACE_SYS_MAX        /*< The number of trace streams that may simultaneously exist in the system.  */
#define TRACE_USER_EVENT_MAX    _POSIX_TRACE_USER_EVENT_MAX /*< The number of user trace event type identifiers that may simultaneously exist in a traced process, including the predefined user trace event POSIX_TRACE_UNNAMED_USER_EVENT.  */
#define TTY_NAME_MAX            _POSIX_TTY_NAME_MAX         /*< The size of the storage required for a terminal device name, in bytes, including the terminating null.  */
#define TZNAME_MAX              _POSIX_TZNAME_MAX           /*< Maximum number of bytes supported for the name of a timezone (not of the TZ variable).  */
#define BC_BASE_MAX             _POSIX2_BC_BASE_MAX         /*< Maximum obase values allowed by the bc utility.  */
#define BC_DIM_MAX              _POSIX2_BC_DIM_MAX          /*< Maximum number of elements permitted in an array by the bc utility.  */
#define BC_SCALE_MAX            _POSIX2_BC_SCALE_MAX        /*< Maximum scale value allowed by the bc utility.  */
#define BC_STRING_MAX           _POSIX2_BC_STRING_MAX       /*< Maximum length of a string constant accepted by the bc utility.  */
#define CHARCLASS_NAME_MAX      _POSIX2_CHARCLASS_NAME_MAX  /*< Maximum number of bytes in a character class name.  */
#define COLL_WEIGHTS_MAX        _POSIX2_COLL_WEIGHTS_MAX    /*< Maximum number of weights that can be assigned to an entry of the LC_COLLATE order keyword in the locale definition file; see Locale.  */
#define EXPR_NEST_MAX           _POSIX2_EXPR_NEST_MAX       /*< Maximum number of expressions that can be nested within parentheses by the expr utility.  */
#define LINE_MAX                _POSIX2_LINE_MAX            /*< Unless otherwise noted, the maximum length, in bytes, of a utility's input line (either standard input or another file), when the utility is described as processing text files. The length includes room for the trailing <newline>.  */
#define RE_DUP_MAX              _POSIX2_RE_DUP_MAX          /*< Maximum number of repeated occurrences of a regular expression permitted when using the interval notation \{m,n\}; see Regular Expressions .  */
#define OV_MAX                  _XOPEN_IOV_MAX              /*< Maximum number of iovec structures that one process has available for use with readv() or writev().  */
#define AME_MAX                 _XOPEN_NAME_MAX             /*< Maximum number of bytes in a filename (not including the terminating null).  */
#define ATH_MAX                 _XOPEN_PATH_MAX             /*< Maximum number of bytes in a pathname.  */



#define NL_ARGMAX	  9			/*< Maximum value of digit in calls to the printf() and scanf() functions. */
#define NL_LANGMAX    14  		/*< Maximum number of bytes in a LANG name. */
#define NL_MSGMAX     32767 	/*< Maximum message number. */
#define NL_NMAX    	  1  		/*< Maximum number of bytes in an N-to-1 collation mapping. */
#define NL_SETMAX     255 		/*< Maximum set number. */
#define NL_TEXTMAX    _POSIX2_LINE_MAX /*< Maximum number of bytes in a message string. */
#define NZERO         20        /*< Default process priority. */



/*
{AIO_PRIO_DELTA_MAX}
    The maximum amount by which a process can decrease its asynchronous I/O priority level from its own scheduling priority.

    Minimum Acceptable Value: 0

{ATEXIT_MAX}
    Maximum number of functions that may be registered with atexit().

    Minimum Acceptable Value: 32
{CHILD_MAX}
    Maximum number of simultaneous processes per real user ID.

    Minimum Acceptable Value: {_POSIX_CHILD_MAX}
{DELAYTIMER_MAX}
    Maximum number of timer expiration overruns.

    Minimum Acceptable Value: {_POSIX_DELAYTIMER_MAX}
{HOST_NAME_MAX}
    Maximum length of a host name (not including the terminating null) as returned from the gethostname() function.

    Minimum Acceptable Value: {_POSIX_HOST_NAME_MAX}
{IOV_MAX}
    Maximum number of iovec structures that one process has available for use with readv() or writev().

    Minimum Acceptable Value: {_XOPEN_IOV_MAX}
{LOGIN_NAME_MAX}
    Maximum length of a login name.

    Minimum Acceptable Value: {_POSIX_LOGIN_NAME_MAX}
{MQ_OPEN_MAX}
    The maximum number of open message queue descriptors a process may hold.

    Minimum Acceptable Value: {_POSIX_MQ_OPEN_MAX}
{MQ_PRIO_MAX}
    The maximum number of message priorities supported by the implementation.

    Minimum Acceptable Value: {_POSIX_MQ_PRIO_MAX}
{OPEN_MAX}
    Maximum number of files that one process can have open at any one time.

    Minimum Acceptable Value: {_POSIX_OPEN_MAX}
	*/
#define PAGESIZE	4096	/*< Size in bytes of a page. */
#define PAGE_SIZE	PAGESIZE	/*< Size in bytes of a page. */

/*
{PTHREAD_DESTRUCTOR_ITERATIONS}
    Maximum number of attempts made to destroy a thread's thread-specific data values on thread exit.

    Minimum Acceptable Value: {_POSIX_THREAD_DESTRUCTOR_ITERATIONS}
{PTHREAD_KEYS_MAX}
    Maximum number of data keys that can be created by a process.

    Minimum Acceptable Value: {_POSIX_THREAD_KEYS_MAX}
{PTHREAD_STACK_MIN}
    Minimum size in bytes of thread stack storage.

    Minimum Acceptable Value: 0
{PTHREAD_THREADS_MAX}
    Maximum number of threads that can be created per process.

    Minimum Acceptable Value: {_POSIX_THREAD_THREADS_MAX}
{RE_DUP_MAX}
    The number of repeated occurrences of a BRE permitted by the regexec() and regcomp() functions when using the interval notation {\(m,n\}; see BREs Matching Multiple Characters .

    Minimum Acceptable Value: {_POSIX2_RE_DUP_MAX}
{RTSIG_MAX}
    Maximum number of realtime signals reserved for application use in this implementation.

    Minimum Acceptable Value: {_POSIX_RTSIG_MAX}
{SEM_NSEMS_MAX}
    Maximum number of semaphores that a process may have.

    Minimum Acceptable Value: {_POSIX_SEM_NSEMS_MAX}
{SEM_VALUE_MAX}
    The maximum value a semaphore may have.

    Minimum Acceptable Value: {_POSIX_SEM_VALUE_MAX}
{SIGQUEUE_MAX}
    Maximum number of queued signals that a process may send and have pending at the receiver(s) at any time.

    Minimum Acceptable Value: {_POSIX_SIGQUEUE_MAX}
{SS_REPL_MAX}
    The maximum number of replenishment operations that may be simultaneously pending for a particular sporadic server scheduler.

    Minimum Acceptable Value: {_POSIX_SS_REPL_MAX}
{STREAM_MAX}
    The number of streams that one process can have open at one time. If defined, it has the same value as {FOPEN_MAX} (see <stdio.h> ).

    Minimum Acceptable Value: {_POSIX_STREAM_MAX}
{SYMLOOP_MAX}
    Maximum number of symbolic links that can be reliably traversed in the resolution of a pathname in the absence of a loop.

    Minimum Acceptable Value: {_POSIX_SYMLOOP_MAX}
{TIMER_MAX}
    Maximum number of timers per process supported by the implementation.

    Minimum Acceptable Value: {_POSIX_TIMER_MAX}
{TRACE_EVENT_NAME_MAX}
    Maximum length of the trace event name.

    Minimum Acceptable Value: {_POSIX_TRACE_EVENT_NAME_MAX}
{TRACE_NAME_MAX}
    Maximum length of the trace generation version string or of the trace stream name.

    Minimum Acceptable Value: {_POSIX_TRACE_NAME_MAX}
{TRACE_SYS_MAX}
    Maximum number of trace streams that may simultaneously exist in the system.

    Minimum Acceptable Value: {_POSIX_TRACE_SYS_MAX}
{TRACE_USER_EVENT_MAX}
    Maximum number of user trace event type identifiers that may simultaneously exist in a traced process, including the predefined user trace event POSIX_TRACE_UNNAMED_USER_EVENT.

    Minimum Acceptable Value: {_POSIX_TRACE_USER_EVENT_MAX}
{TTY_NAME_MAX}
    Maximum length of terminal device name.

    Minimum Acceptable Value: {_POSIX_TTY_NAME_MAX}
{TZNAME_MAX}
    Maximum number of bytes supported for the name of a timezone (not of the TZ variable).

    Minimum Acceptable Value: {_POSIX_TZNAME_MAX}
Note:
    The length given by {TZNAME_MAX} does not include the quoting characters mentioned in Other Environment Variables .

Pathname Variable Values

The values in the following list may be constants within an implementation or may vary from one pathname to another. For example, file systems or directories may have different characteristics.

A definition of one of the values shall be omitted from the <limits.h> header on specific implementations where the corresponding value is equal to or greater than the stated minimum, but where the value can vary depending on the file to which it is applied. The actual value supported for a specific pathname shall be provided by the pathconf() function.

{FILESIZEBITS}
    Minimum number of bits needed to represent, as a signed integer value, the maximum size of a regular file allowed in the specified directory.

    Minimum Acceptable Value: 32
{LINK_MAX}
    Maximum number of links to a single file.

    Minimum Acceptable Value: {_POSIX_LINK_MAX}
{MAX_CANON}
    Maximum number of bytes in a terminal canonical input line.

    Minimum Acceptable Value: {_POSIX_MAX_CANON}
{MAX_INPUT}
    Minimum number of bytes for which space is available in a terminal input queue; therefore, the maximum number of bytes a conforming application may require to be typed as input before reading them.

    Minimum Acceptable Value: {_POSIX_MAX_INPUT}
{NAME_MAX}
    Maximum number of bytes in a filename (not including terminating null).

    Minimum Acceptable Value: {_POSIX_NAME_MAX}

    Minimum Acceptable Value: {_XOPEN_NAME_MAX}
{PATH_MAX}
    Maximum number of bytes in a pathname, including the terminating null character.

    Minimum Acceptable Value: {_POSIX_PATH_MAX}

    Minimum Acceptable Value: {_XOPEN_PATH_MAX}
{PIPE_BUF}
    Maximum number of bytes that is guaranteed to be atomic when writing to a pipe.

    Minimum Acceptable Value: {_POSIX_PIPE_BUF}
{POSIX_ALLOC_SIZE_MIN}
    Minimum number of bytes of storage actually allocated for any portion of a file.

    Minimum Acceptable Value: Not specified.
{POSIX_REC_INCR_XFER_SIZE}
    Recommended increment for file transfer sizes between the {POSIX_REC_MIN_XFER_SIZE} and {POSIX_REC_MAX_XFER_SIZE} values.

    Minimum Acceptable Value: Not specified.
{POSIX_REC_MAX_XFER_SIZE}
    Maximum recommended file transfer size.

    Minimum Acceptable Value: Not specified.
{POSIX_REC_MIN_XFER_SIZE}
    Minimum recommended file transfer size.

    Minimum Acceptable Value: Not specified.
{POSIX_REC_XFER_ALIGN}
    Recommended file transfer buffer alignment.

    Minimum Acceptable Value: Not specified.
{SYMLINK_MAX}
    Maximum number of bytes in a symbolic link.

    Minimum Acceptable Value: {_POSIX_SYMLINK_MAX}

Runtime Increasable Values

The magnitude limitations in the following list shall be fixed by specific implementations. An application should assume that the value supplied by <limits.h> in a specific implementation is the minimum that pertains whenever the application is run under that implementation. A specific instance of a specific implementation may increase the value relative to that supplied by <limits.h> for that implementation. The actual value supported by a specific instance shall be provided by the sysconf() function.

{BC_BASE_MAX}
    Maximum obase values allowed by the bc utility.

    Minimum Acceptable Value: {_POSIX2_BC_BASE_MAX}
{BC_DIM_MAX}
    Maximum number of elements permitted in an array by the bc utility.

    Minimum Acceptable Value: {_POSIX2_BC_DIM_MAX}
{BC_SCALE_MAX}
    Maximum scale value allowed by the bc utility.

    Minimum Acceptable Value: {_POSIX2_BC_SCALE_MAX}
{BC_STRING_MAX}
    Maximum length of a string constant accepted by the bc utility.

    Minimum Acceptable Value: {_POSIX2_BC_STRING_MAX}
{CHARCLASS_NAME_MAX}
    Maximum number of bytes in a character class name.

    Minimum Acceptable Value: {_POSIX2_CHARCLASS_NAME_MAX}
{COLL_WEIGHTS_MAX}
    Maximum number of weights that can be assigned to an entry of the LC_COLLATE order keyword in the locale definition file; see Locale .

    Minimum Acceptable Value: {_POSIX2_COLL_WEIGHTS_MAX}
{EXPR_NEST_MAX}
    Maximum number of expressions that can be nested within parentheses by the expr utility.

    Minimum Acceptable Value: {_POSIX2_EXPR_NEST_MAX}
{LINE_MAX}
    Unless otherwise noted, the maximum length, in bytes, of a utility's input line (either standard input or another file), when the utility is described as processing text files. The length includes room for the trailing <newline>.

    Minimum Acceptable Value: {_POSIX2_LINE_MAX}
{NGROUPS_MAX}
    Maximum number of simultaneous supplementary group IDs per process.

    Minimum Acceptable Value: {_POSIX_NGROUPS_MAX}
{RE_DUP_MAX}
    Maximum number of repeated occurrences of a regular expression permitted when using the interval notation \{m,n\}; see Regular Expressions .

    Minimum Acceptable Value: {_POSIX2_RE_DUP_MAX}

Maximum Values

The symbolic constants in the following list shall be defined in <limits.h> with the values shown. These are symbolic names for the most restrictive value for certain features on an implementation supporting the Timers option. A conforming implementation shall provide values no larger than these values. A conforming application must not require a smaller value for correct operation.

{_POSIX_CLOCKRES_MIN}
    The resolution of the CLOCK_REALTIME clock, in nanoseconds.

    Value: 20 000 000

If the Monotonic Clock option is supported, the resolution of the CLOCK_MONOTONIC clock, in nanoseconds, is represented by {_POSIX_CLOCKRES_MIN}.
Minimum Values

The symbolic constants in the following list shall be defined in <limits.h> with the values shown. These are symbolic names for the most restrictive value for certain features on an implementation conforming to this volume of IEEE Std 1003.1-2001. Related symbolic constants are defined elsewhere in this volume of IEEE Std 1003.1-2001 which reflect the actual implementation and which need not be as restrictive. A conforming implementation shall provide values at least this large. A strictly conforming application must not require a larger value for correct operation.
*/


/* ===========================================================================
			Check POSIX support
=========================================================================== */

#if AIO_LISTIO_MAX < _POSIX_AIO_LISTIO_MAX
#  error " Value AIO_LISTIO_MAX doesn't support POSIX "
#endif
#if AIO_MAX < _POSIX_AIO_MAX
#  error " Value AIO_MAX doesn't support POSIX "
#endif
#if ARG_MAX < _POSIX_ARG_MAX
#  error " Value ARG_MAX doesn't support POSIX "
#endif
#if CHILD_MAX < _POSIX_CHILD_MAX
#  error " Value CHILD_MAX doesn't support POSIX "
#endif
#if DELAYTIMER_MAX < _POSIX_DELAYTIMER_MAX
#  error " Value DELAYTIMER_MAX doesn't support POSIX "
#endif
#if HOST_NAME_MAX < _POSIX_HOST_NAME_MAX
#  error " Value HOST_NAME_MAX doesn't support POSIX "
#endif
#if LINK_MAX < _POSIX_LINK_MAX
#  error " Value LINK_MAX doesn't support POSIX "
#endif
#if LOGIN_NAME_MAX < _POSIX_LOGIN_NAME_MAX
#  error " Value LOGIN_NAME_MAX doesn't support POSIX "
#endif
#if MAX_CANON < _POSIX_MAX_CANON
#  error " Value MAX_CANON doesn't support POSIX "
#endif
#if MAX_INPUT < _POSIX_MAX_INPUT
#  error " Value MAX_INPUT doesn't support POSIX "
#endif
#if MQ_OPEN_MAX < _POSIX_MQ_OPEN_MAX
#  error " Value MQ_OPEN_MAX doesn't support POSIX "
#endif
#if MQ_PRIO_MAX < _POSIX_MQ_PRIO_MAX
#  error " Value MQ_PRIO_MAX doesn't support POSIX "
#endif
#if NAME_MAX < _POSIX_NAME_MAX
#  error " Value NAME_MAX doesn't support POSIX "
#endif
#if NGROUPS_MAX < _POSIX_NGROUPS_MAX
#  error " Value NGROUPS_MAX doesn't support POSIX "
#endif
#if OPEN_MAX < _POSIX_OPEN_MAX
#  error " Value OPEN_MAX doesn't support POSIX "
#endif
#if PATH_MAX < _POSIX_PATH_MAX
#  error " Value PATH_MAX doesn't support POSIX "
#endif
#if PIPE_BUF < _POSIX_PIPE_BUF
#  error " Value PIPE_BUF doesn't support POSIX "
#endif
#if RE_DUP_MAX < _POSIX_RE_DUP_MAX
#  error " Value RE_DUP_MAX doesn't support POSIX "
#endif
#if RTSIG_MAX < _POSIX_RTSIG_MAX
#  error " Value RTSIG_MAX doesn't support POSIX "
#endif
#if SEM_NSEMS_MAX < _POSIX_SEM_NSEMS_MAX
#  error " Value SEM_NSEMS_MAX doesn't support POSIX "
#endif
#if SEM_VALUE_MAX < _POSIX_SEM_VALUE_MAX
#  error " Value SEM_VALUE_MAX doesn't support POSIX "
#endif
#if SIGQUEUE_MAX < _POSIX_SIGQUEUE_MAX
#  error " Value SIGQUEUE_MAX doesn't support POSIX "
#endif
#if SSIZE_MAX < _POSIX_SSIZE_MAX
#  error " Value SSIZE_MAX doesn't support POSIX "
#endif
#if STREAM_MAX < _POSIX_STREAM_MAX
#  error " Value STREAM_MAX doesn't support POSIX "
#endif
#if SS_REPL_MAX < _POSIX_SS_REPL_MAX
#  error " Value SS_REPL_MAX doesn't support POSIX "
#endif
#if SYMLINK_MAX < _POSIX_SYMLINK_MAX
#  error " Value SYMLINK_MAX doesn't support POSIX "
#endif
#if SYMLOOP_MAX < _POSIX_SYMLOOP_MAX
#  error " Value SYMLOOP_MAX doesn't support POSIX "
#endif
#if THREAD_DESTRUCTOR_ITERATIONS < _POSIX_THREAD_DESTRUCTOR_ITERATIONS
#  error " Value THREAD_DESTRUCTOR_ITERATIONS doesn't support POSIX "
#endif
#if THREAD_KEYS_MAX < _POSIX_THREAD_KEYS_MAX
#  error " Value THREAD_KEYS_MAX doesn't support POSIX "
#endif
#if THREAD_THREADS_MAX < _POSIX_THREAD_THREADS_MAX
#  error " Value THREAD_THREADS_MAX doesn't support POSIX "
#endif
#if TIMER_MAX < _POSIX_TIMER_MAX
#  error " Value TIMER_MAX doesn't support POSIX "
#endif
#if TRACE_EVENT_NAME_MAX < _POSIX_TRACE_EVENT_NAME_MAX
#  error " Value TRACE_EVENT_NAME_MAX doesn't support POSIX "
#endif
#if TRACE_NAME_MAX < _POSIX_TRACE_NAME_MAX
#  error " Value TRACE_NAME_MAX doesn't support POSIX "
#endif
#if TRACE_SYS_MAX < _POSIX_TRACE_SYS_MAX
#  error " Value TRACE_SYS_MAX doesn't support POSIX "
#endif
#if TRACE_USER_EVENT_MAX < _POSIX_TRACE_USER_EVENT_MAX
#  error " Value TRACE_USER_EVENT_MAX doesn't support POSIX "
#endif
#if TTY_NAME_MAX < _POSIX_TTY_NAME_MAX
#  error " Value TTY_NAME_MAX doesn't support POSIX "
#endif
#if TZNAME_MAX < _POSIX_TZNAME_MAX
#  error " Value TZNAME_MAX doesn't support POSIX "
#endif
#if BC_BASE_MAX < _POSIX2_BC_BASE_MAX
#  error " Value BC_BASE_MAX doesn't support POSIX "
#endif
#if BC_DIM_MAX < _POSIX2_BC_DIM_MAX
#  error " Value BC_DIM_MAX doesn't support POSIX "
#endif
#if BC_SCALE_MAX < _POSIX2_BC_SCALE_MAX
#  error " Value BC_SCALE_MAX doesn't support POSIX "
#endif
#if BC_STRING_MAX < _POSIX2_BC_STRING_MAX
#  error " Value BC_STRING_MAX doesn't support POSIX "
#endif
#if CHARCLASS_NAME_MAX < _POSIX2_CHARCLASS_NAME_MAX
#  error " Value CHARCLASS_NAME_MAX doesn't support POSIX "
#endif
#if COLL_WEIGHTS_MAX < _POSIX2_COLL_WEIGHTS_MAX
#  error " Value COLL_WEIGHTS_MAX doesn't support POSIX "
#endif
#if EXPR_NEST_MAX < _POSIX2_EXPR_NEST_MAX
#  error " Value EXPR_NEST_MAX doesn't support POSIX "
#endif
#if LINE_MAX < _POSIX2_LINE_MAX
#  error " Value LINE_MAX doesn't support POSIX "
#endif
#if RE_DUP_MAX < _POSIX2_RE_DUP_MAX
#  error " Value RE_DUP_MAX doesn't support POSIX "
#endif
#if OV_MAX < _XOPEN_IOV_MAX
#  error " Value OV_MAX doesn't support POSIX "
#endif
#if AME_MAX < _XOPEN_NAME_MAX
#  error " Value AME_MAX doesn't support POSIX "
#endif
#if ATH_MAX < _XOPEN_PATH_MAX
#  error " Value ATH_MAX doesn't support POSIX "
#endif

/* ----------------------------------------------------------------------- */

#endif /* LIMITS_H__ */
