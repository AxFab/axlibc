#ifndef TIME_H__
#define TIME_H__

/** @file time.h
 * @brief time types
 * @version C89, C99, IEEE, Unix95, Unix98, POSIX, XSI
 *
 */

#include <stddef.h>
#include <sys/types.h>

__AXLIBC_BEG

// ===========================================================================
/** Number of clock ticks per second returned by the times() function. */
#define CLK_TCK

/** A number used to convert the value returned by the clock() function into
 seconds. */
#define CLOCKS_PER_SEC  1000000

/** The identifier of the CPU-time clock associated with the process making a
 * clock() or timer*() function call. */
#define CLOCK_PROCESS_CPUTIME_ID  2

/** The identifier of the CPU-time clock associated with the thread making a
 * clock() or timer*() function call. */
#define CLOCK_THREAD_CPUTIME_ID   3

/** The identifier of the system-wide realtime clock. */
#define CLOCK_REALTIME            1

/** Flag indicating time is absolute. For functions taking timer objects, this refers to the clock associated with the timer. [Option End] */
#define TIMER_ABSTIME             4

/** The identifier for the system-wide monotonic clock, which is defined as a clock whose value cannot be set via clock_settime() and which cannot have backward clock jumps. The maximum possible clock jump shall be implementation-defined. */
#define CLOCK_MONOTONIC           5



// ===========================================================================
struct tm
{
  int    tm_sec;   /**< seconds [0,61] */
  int    tm_min;   /**< minutes [0,59] */
  int    tm_hour;  /**< hour [0,23] */
  int    tm_mday;  /**< day of month [1,31] */
  int    tm_mon;   /**< month of year [0,11] */
  int    tm_year;  /**< years since 1900 */
  int    tm_wday;  /**< day of week [0,6] (Sunday = 0) */
  int    tm_yday;  /**< day of year [0,365] */
  int    tm_isdst; /**< daylight savings flag */
};

struct timespec
{
  time_t  tv_sec;    /**< Seconds. */
  long    tv_nsec;   /**< Nanoseconds. */
};

int tm_isdst;

struct itimerspec
{
  struct timespec  it_interval;  /**< Timer period. */
  struct timespec  it_value;     /**< Timer expiration. */
};


// ===========================================================================
char      *asctime(const struct tm *);
char      *asctime_r(const struct tm *restrict, char *restrict);
clock_t    clock(void);
int        clock_getcpuclockid(pid_t, clockid_t *);
int        clock_getres(clockid_t, struct timespec *);
int        clock_gettime(clockid_t, struct timespec *);
int        clock_nanosleep(clockid_t, int, const struct timespec *,struct timespec *);
int        clock_settime(clockid_t, const struct timespec *);
char      *ctime(const time_t *);
char      *ctime_r(const time_t *, char *);
double     difftime(time_t, time_t);
struct tm *getdate(const char *);
struct tm *gmtime(const time_t *);
struct tm *gmtime_r(const time_t *restrict, struct tm *restrict);
struct tm *localtime(const time_t *);
struct tm *localtime_r(const time_t *restrict, struct tm *restrict);
time_t     mktime(struct tm *);
int        nanosleep(const struct timespec *, struct timespec *);
size_t     strftime(char *restrict, size_t, const char *restrict, const struct tm *restrict);
char      *strptime(const char *restrict, const char *restrict, struct tm *restrict);
time_t     time(time_t *);
// int        timer_create(clockid_t, struct sigevent *restrict, timer_t *restrict);
// int        timer_delete(timer_t);
// int        timer_gettime(timer_t, struct itimerspec *);
// int        timer_getoverrun(timer_t);
// int        timer_settime(timer_t, int, const struct itimerspec *restrict, struct itimerspec *restrict);
void       tzset(void);


extern int    daylight;
extern long   timezone;
extern char  *tzname[];





__AXLIBC_END

#endif /* TIME_H__ */
