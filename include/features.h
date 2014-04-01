#ifndef FEATURES_H__
#define FEATURES_H__

/*
  These macros are defined by the user or compiler:

   __STRICT_ANSI__               ISO Standard C. (C89)
   _ISOC99_SOURCE                Extensions to ISO C89 from ISO C99.
   _POSIX_SOURCE                 IEEE Std 1003.1.
   _POSIX_C_SOURCE
      1                          Eq. _POSIX_SOURCE
      > 2                        Add IEEE Std 1003.2
      > 199309L                  Add IEEE Std 1003.1b-1993
      > 199506L                  Add IEEE Std 1003.1c-1995
      > 200112L                  Add IEEE 1003.1-2004
      > 200809L                  Add IEEE 1003.1-2008

   _XOPEN_SOURCE                 Includes POSIX and XPG things.
      500                        Single Unix conformance
      600                        6th revision
      700                        7th revision
   _XOPEN_SOURCE_EXTENDED        XPG things and X/Open Unix extensions.
   _LARGEFILE_SOURCE             Some more functions for correct standard I/O.
   _LARGEFILE64_SOURCE           Additional functionality from LFS for large files.
   _FILE_OFFSET_BITS=N           Select default filesystem interface.
   _BSD_SOURCE                   ISO C, POSIX, and 4.3BSD things.
   _SVID_SOURCE                  ISO C, POSIX, and SVID things.
   _ATFILE_SOURCE                Additional *at interfaces.
   _GNU_SOURCE                   All of the above, plus GNU extensions.
   _REENTRANT                    Select additionally reentrant object.
   _THREAD_SAFE                  Same as _REENTRANT, often used by other systems.
   _FORTIFY_SOURCE               Additional security measures are defined, according to level.

   If none are define, we use last posix version

   We simplify this diagram by this one:

      C89 _ C99 _ UNX  _ XOPN
                \ IEEE _ BSD
                       \ SVID

      + _IO_EXT: _LARGEFILE_SOURCE + _LARGEFILE64_SOURCE
      + _THREAD_SAFE: _REENTRANT | _THREAD_SAFE
      + _FORTIFY_SOURCE
      + _ATFILE_SOURCE
*/

// ---------------------------------------------------------------------------
// Simplify inclusions
#ifdef _GNU_SOURCE
#  define _BSD_SOURCE
#  define _SVID_SOURCE
#  define _XOPEN_SOURCE_EXTENDED
#endif

#if defined(_REENTRANT)
#  define _THREAD_SAFE
#endif

#if defined(_LARGEFILE_SOURCE) || defined(_LARGEFILE64_SOURCE)
#  define _IO_EXT
#endif

#if defined (_SVID_SOURCE)
# define __SVID
#endif

#if defined (_BSD_SOURCE)
# define __BSD
#endif

#if defined (_XOPEN_SOURCE_EXTENDED)
# define __XOPN
#endif

#if defined (_XOPEN_SOURCE)
# define __UNX
#endif

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE)
#  define __IEEE
#endif

#if defined(_ISOC99_SOURCE)
#  define __C99
#endif

#if defined (__STRICT_ANSI__)
#  define __C89
#endif

// ---------------------------------------------------------------------------
// Resolve dependancies

#if defined(__BSD) || defined(__SVID)
#  define __IEEE
#endif

#if defined(__XOPN)
#  define __UNX
#endif

#if defined(__UNX) || defined(__IEEE)
#  define __C99
#endif

#if defined(__C99)
#  define __C89
#endif

// Default, use
#ifndef __C89
#  define __C89
#  define __C99
#  define __IEEE
#endif

// ---------------------------------------------------------------------------
// Header file prolog and epilog
#ifdef __cplusplus
#  define __AXLIBC_BEG      extern "C" {
#  define __AXLIBC_END      }
#else
#  define __AXLIBC_BEG
#  define __AXLIBC_END
#endif



// ---------------------------------------------------------------------------
__AXLIBC_BEG

#define __axlog(msg, ...)   ((void)(0))

__AXLIBC_END

#endif /* FEATURES_H__ */
