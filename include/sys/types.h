#ifndef SYS_TYPES_H__
#define SYS_TYPES_H__

/** @file sys/types.h
 * @brief data types
 * @version IEEE, Unix95, Unix98, POSIX, XSI
 * 
 */

#include <stdint.h>

__AXLIBC_BEG

/* ===========================================================================
  System Identified
=========================================================================== */

/** Used as a general identifier; can be used to contain at least a pid_t, 
 * uid_t, or gid_t.  */
typedef long id_t;

/** Used for process IDs and process group IDs. */
typedef id_t pid_t;

/** Used for group IDs. */
typedef id_t gid_t;

/** Used for user IDs. */
typedef id_t uid_t;


/** Used for device IDs. */
typedef id_t dev_t;

/** Used for file serial numbers. */
typedef uintmax_t ino_t;


/* ===========================================================================
  Length related types
=========================================================================== */

/** Used for file block counts. */
typedef long blkcnt_t

/** Used for block sizes. */
typedef int blksize_t
    
/** Used for file system block counts.  */
typedef unsigned long fsblkcnt_t;

/** Used for file system file counts.  */
typedef unsigned int fsfilcnt_t

/** Used for link counts. */
typedef long nlink_t;

/** Used for file sizes. */
typedef long off_t;

/** Used for sizes of objects. */
typedef uintptr_t size_t;

/** Used for a count of bytes or an error indication. */
typedef intptr_t ssize_t;


/* ===========================================================================
  Time related types
=========================================================================== */

/** Used for system times in clock ticks or CLOCKS_PER_SEC; see <time.h>. */
typedef long clock_t;
    
/** Used for clock ID type in the clock and timer functions. */
typedef int clockid_t;

/** Used for time in microseconds.  */
typedef signed long suseconds_t;

/** Used for time in seconds. */
typedef long time_t;

/** Used for timer ID returned by timer_create().  */
typedef id_t timer_t;

/** Used for time in microseconds.  */
typedef unsigned long useconds_t;


/* ===========================================================================
  Others
=========================================================================== */


/** Used for XSI interprocess communication.  */
typedef int key_t;

/** Used for some file attributes. */
typedef int_fast16_t mode_t;

/** Used to identify a trace stream attributes object.  */
typedef int trace_attr_t;

/** Used to identify a trace event type.  */
typedef int trace_event_id_t;

/** Used to identify a trace event type set.  */
typedef int trace_event_set_t;

/** Used to identify a trace stream.  */
typedef int trace_id_t;



#if 0
typedef int pthread_attr_t;
     Used to identify a thread attribute object. 
pthread_barrier_t
    [BAR] Used to identify a barrier. 
pthread_barrierattr_t
    [BAR] Used to define a barrier attributes object. 
pthread_cond_t
     Used for condition variables. 
pthread_condattr_t
     Used to identify a condition attribute object. 
pthread_key_t
     Used for thread-specific data keys. 
pthread_mutex_t
     Used for mutexes. 
pthread_mutexattr_t
     Used to identify a mutex attribute object. 
pthread_once_t
     Used for dynamic package initialization. 
pthread_rwlock_t
     Used for read-write locks. 
pthread_rwlockattr_t
     Used for read-write lock attributes. 
pthread_spinlock_t
    [SPI] Used to identify a spin lock. 
pthread_t
     Used to identify a thread. 
#endif


__AXLIBC_END

#endif /* SYS_TYPES_H__ */
