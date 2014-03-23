#include <string.h>

#define LINE_MAX 256

extern char* errMsgs[];

static char _strerror_tmp[LINE_MAX];

static const char* strerror_p ( int err )
{
  if ( err == 0 ) {
    return "No error"; 
  }

  int grp = err & 0x1fff00;


  switch ( grp ) {
    case 0:
    // TODO ERANGE, try with sizeof !
    return errMsgs[err]; 

    default:
      return "Unknown Error";
  }
}

/* Copy error string on the buffer */
int strerror_r (int err, char* buffer, size_t length)
{
  const char* str;
  if (buffer == NULL || length == 0)
    return -1;
  str = strerror_p ( err );
  strncpy ( buffer, str, length );
  return strlen(str) <= length ? 0 : -1;
}


/* Copy error string on the buffer */
void strerror_s ( char* str, size_t length, int err )
{
  strncpy ( str, strerror_p ( err ), length );
}


/* Return error string */
char* strerror ( int err )
{
  return strncpy ( _strerror_tmp, strerror_p ( err ), LINE_MAX );
}

/* return length of a null-terminated char string */
size_t strlen ( const char* str )
{
  register const char* end = str;

  while ( *end ) {
    ++end;
  }

  return end - str;
}

/* return length of a null-terminated char string */
size_t strnlen ( const char* str, size_t length )
{
  register size_t count;

  for ( count = 0; count < length && *str; ++str );

  return count;
}


// ERROR MESSAGES
char* errMsgs[] = {
  "",
  "Operation not permitted", // EPERM
  "No such file or directory",
  "No such process",
  "Interrupted system call",
  "I/O error",
  "No such device or address",
  "Argument list too long",
  "Exec format error",
  "Bad file number",
  "No child processes",
  "Try again", // EAGAIN
  "Out of memory",
  "Permission denied",
  "Bad address",
  "Block device required",
  "Device or resource busy",
  "File exists",
  "Cross-device link",
  "No such device",
  "Not a directory",
  "Is a directory",
  "Invalid argument",
  "File table overflow",
  "Too many open files",
  "Not a typewriter",
  "Text file busy",
  "File too large",
  "No space left on device",
  "Illegal seek",
  "Read-only file system",
  "Too many links",
  "Broken pipe",
  "Math argument out of domain of func",
  "Math result not representable",
  "Resource deadlock would occur", // EDEADLK
  "File name too long",
  "No record locks available",
  "Function not implemented",
  "Directory not empty",
  "Too many symbolic links encountered",
  "Operation would block", // EWOULDBLOCK => EAGAIN
  "No message of desired type", 
  "Identifier removed",
  "Channel number out of range",
  "Level 2 not synchronized",
  "Level 3 halted",
  "Level 3 reset",
  "Link number out of range",
  "Protocol driver not attached",
  "No CSI structure available",
  "Level 2 halted",
  "Invalid exchange",
  "Invalid request descriptor",
  "Exchange full",
  "No anode",
  "Invalid request code",
  "Invalid slot",
  "Resource deadlock would occur", // EDEADLOCK => EDEADLK
  "Bad font file format",
  "Device not a stream",
  "No data available",
  "Timer expired",
  "Out of streams resources",
  "Machine is not on the network",
  "Package not installed",
  "Object is remote",
  "Link has been severed",
  "Advertise error",
  "Srmount error",
  "Communication error on send",
  "Protocol error",
  "Multihop attempted",
  "RFS specific error",
  "Not a data message",
  "Value too large for defined data type",
  "Name not unique on network",
  "File descriptor in bad state",
  "Remote address changed",
  "Can not access a needed shared library",
  "Accessing a corrupted shared library",
  ".lib section in a.out corrupted",
  "Attempting to link in too many shared libraries",
  "Cannot exec a shared library directly",
  "Illegal byte sequence",
  "Interrupted system call should be restarted",
  "Streams pipe error",
  "Too many users",
  "Socket operation on non-socket",
  "Destination address required",
  "Message too long",
  "Protocol wrong type for socket",
  "Protocol not available",
  "Protocol not supported",
  "Socket type not supported",
  "Operation not supported on transport endpoint",
  "Protocol family not supported",
  "Address family not supported by protocol",
  "Address already in use",
  "Cannot assign requested address",
  "Network is down",
  "Network is unreachable",
  "Network dropped connection because of reset",
  "Software caused connection abort",
  "Connection reset by peer",
  "No buffer space available",
  "Transport endpoint is already connected",
  "Transport endpoint is not connected",
  "Cannot send after transport endpoint shutdown",
  "Too many references: cannot splice",
  "Connection timed out",
  "Connection refused",
  "Host is down",
  "No route to host",
  "Operation already in progress",
  "Operation now in progress",
  "Stale NFS file handle",
  "Structure needs cleaning",
  "Not a XENIX named type file",
  "No XENIX semaphores available",
  "Is a named type file",
  "Remote I/O error",
  "Quota exceeded",
  "No medium found",
  "Wrong medium type",
  "Operation Canceled",
  "Required key not available",
  "Key has expired",
  "Key has been revoked",
  "Key was rejected by service",
};

