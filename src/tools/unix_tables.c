#include <stdio.h>

/*

      C89 _ C99 _ UNX  _ XOPN
                \ IEEE _ BSD
                       \ SVID

  __C89  Include header of C89 and C89_OPT
  __C99  Include header of C89 and C89_OPT
  __UNX  Include header of P_UNIX_98 and P_UNIX_OPT
  ___IEEE               of P_IEEE *
  ___XOPN               of P_XSI 
  __BSD, __SVID         of P_POSIX and P_POSIX_OPT
*/


#define P_XSI_OPT         0x1000 
#define P_XSI             0x0800
#define P_POSIX_OPT       0x0400
#define P_POSIX           0x0200

#define P_UNIX_OPT        0x0100
#define P_UNIX            0x0040
#define P_UNIX_98         0x0080 | P_UNIX

#define P_IEEE_RT         0x0020
#define P_IEEE_TH         0x0010
#define P_IEEE            0x0008

#define P_C99             0x0004
#define P_C89_OPT         0x0002 | P_C99
#define P_C89             0x0001


struct axHeaderTable {
  const char*   _name;
  int           _flags;
}


axHeaderTable [] = {
  "aio.h",          P_XSI_OPT | P_POSIX_OPT | P_UNIX_OPT | P_IEEE_RT, 
  "arpa/inet.h",    P_XSI | P_POSIX | P_UNIX, 
  "assert.h",       P_XSI | P_POSIX | P_UNIX | P_C89, 
  "complex.h",      P_XSI | P_POSIX | P_C99, 
  "cpio.h",         P_XSI | P_POSIX_OPT | P_UNIX, 
  "ctype.h",        P_XSI | P_POSIX | P_UNIX | P_C89, 
  "dirent.h",       P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "dlfcn.h",        P_XSI | P_POSIX_OPT | P_UNIX_98, 
  "errno.h",        P_XSI | P_POSIX | P_UNIX | P_IEEE | P_C89, 
  "fcntl.h",        P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "fenv.h",         P_XSI | P_POSIX | P_C99, 
  "float.h",        P_XSI | P_POSIX | P_UNIX | P_IEEE | P_C89, 
  "fmtmsg.h",       P_XSI | P_POSIX_OPT | P_UNIX | P_IEEE, 
  "fnmatch.h",      P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "ftw.h",          P_XSI | P_POSIX_OPT | P_UNIX, 
  "glob.h",         P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "grp.h",          P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "iconv.h",        P_XSI | P_POSIX_OPT | P_UNIX, 
  "inttypes.h",     P_XSI | P_POSIX | P_UNIX_98 | P_C99, 
  "iso646.h",       P_XSI | P_POSIX | P_UNIX_98 | P_C89_OPT, 
  "langinfo.h",     P_XSI | P_POSIX_OPT | P_UNIX, 
  "libgen.h",       P_XSI | P_POSIX_OPT | P_UNIX, 
  "limits.h",       P_XSI | P_POSIX | P_UNIX | P_IEEE | P_C89, 
  "locale.h",       P_XSI | P_POSIX | P_UNIX | P_IEEE | P_C89, 
  "math.h",         P_XSI | P_POSIX | P_UNIX | P_IEEE | P_C89, 
  "monetary.h",     P_XSI | P_POSIX_OPT | P_UNIX, 
  "mqueue.h",       P_XSI_OPT | P_POSIX_OPT | P_UNIX_OPT | P_IEEE_RT, 
  "ndbm.h",         P_XSI | P_POSIX_OPT | P_UNIX, 
  "net/if.h",       P_XSI | P_POSIX | P_UNIX, 
  "netdb.h",        P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "netinet/in.h",   P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "netinet/tcp.h",  P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "nl_types.h",     P_XSI | P_POSIX_OPT | P_UNIX, 
  "poll.h",         P_XSI | P_POSIX | P_UNIX, 
  "pthread.h",      P_XSI | P_POSIX_OPT | P_UNIX_98| P_IEEE_TH, 
  "pwd.h",          P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "regex.h",        P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "sched.h",        P_XSI_OPT | P_POSIX_OPT | P_UNIX_OPT | P_IEEE_RT, 
  "search.h",       P_XSI | P_POSIX_OPT | P_UNIX, 
  "semaphore.h",    P_XSI_OPT | P_POSIX_OPT | P_UNIX_OPT | P_IEEE_RT, 
  "setjmp.h",       P_XSI | P_POSIX | P_UNIX | P_IEEE | P_C89, 
  "signal.h",       P_XSI | P_POSIX | P_UNIX | P_IEEE | P_C89, 
  "spawn.h",        P_XSI_OPT | P_POSIX_OPT, 
  "stdarg.h",       P_XSI | P_POSIX | P_UNIX | P_IEEE | P_C89, 
  "stdbool.h",      P_XSI | P_POSIX | P_UNIX | P_IEEE | P_C99, 
  "stddef.h",       P_XSI | P_POSIX | P_UNIX | P_IEEE | P_C89, 
  "stdint.h",       P_XSI | P_POSIX | P_C99, 
  "stdio.h",        P_XSI | P_POSIX | P_UNIX | P_IEEE | P_C89, 
  "stdlib.h",       P_XSI | P_POSIX | P_UNIX | P_IEEE | P_C89, 
  "string.h",       P_XSI | P_POSIX | P_UNIX | P_IEEE | P_C89, 
  "strings.h",      P_XSI | P_POSIX_OPT | P_UNIX, 
  "stropts.h",      P_XSI | P_POSIX_OPT | P_UNIX, 
  "sys/ipc.h",      P_XSI | P_POSIX_OPT | P_UNIX, 
  "sys/mman.h",     P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "sys/msg.h",      P_XSI | P_POSIX_OPT | P_UNIX, 
  "sys/resource.h", P_XSI | P_POSIX_OPT | P_UNIX, 
  "sys/select.h",   P_XSI | P_POSIX | P_UNIX, 
  "sys/sem.h",      P_XSI | P_POSIX_OPT | P_UNIX | P_IEEE, 
  "sys/shm.h",      P_XSI | P_POSIX_OPT | P_UNIX, 
  "sys/socket.h",   P_XSI | P_POSIX | P_UNIX, 
  "sys/stat.h",     P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "sys/statvfs.h",  P_XSI | P_POSIX_OPT | P_UNIX | P_IEEE, 
  "sys/time.h",     P_XSI | P_POSIX | P_UNIX, 
  "sys/timeb.h",    P_XSI | P_POSIX_OPT | P_UNIX, 
  "sys/times.h",    P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "sys/types.h",    P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "sys/uio.h",      P_XSI | P_POSIX_OPT | P_UNIX, 
  "sys/un.h",       P_XSI | P_POSIX_OPT | P_UNIX, 
  "sys/utsname.h",  P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "sys/wait.h",     P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "syslog.h",       P_XSI | P_POSIX_OPT | P_UNIX, 
  "tar.h",          P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "termios.h",      P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "tgmath.h",       P_XSI | P_POSIX | P_C99, 
  "time.h",         P_XSI | P_POSIX | P_UNIX | P_C89, 
  "trace.h",        P_XSI_OPT | P_POSIX_OPT, 
  "ucontext.h",     P_XSI | P_POSIX_OPT | P_UNIX, 
  "ulimit.h",       P_XSI | P_POSIX_OPT | P_UNIX, 
  "unistd.h",       P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "utime.h",        P_XSI | P_POSIX | P_UNIX | P_IEEE, 
  "utmpx.h",        P_XSI | P_POSIX_OPT | P_UNIX, 
  "wchar.h",        P_XSI | P_POSIX | P_UNIX | P_C89_OPT, 
  "wctype.h",       P_XSI | P_POSIX | P_UNIX | P_C89_OPT, 
  "wordexp.h",      P_XSI | P_POSIX | P_UNIX | P_IEEE, 


};

int main () 
{
  int i = 0; 
  int mask = P_C89;
  char tmp [512];

  for (i = 0; i < 84; ++i) {

    if (axHeaderTable[i]._flags & mask) {

      strcpy (tmp, "include/");
      strcat (tmp, axHeaderTable[i]._name);
      FILE* fp = fopen (tmp, "r");
      if (!fp) {
        printf ("%s\n", axHeaderTable[i]._name);
      } else {
        fclose (fp);
      }
    }

    // printf ("%5d\t%s\n", axHeaderTable[i]._flags, axHeaderTable[i]._name);
  }

  return 0;
}



