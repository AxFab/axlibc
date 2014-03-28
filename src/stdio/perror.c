#include <prv/stream.h>
#include <errno.h>
#include <string.h>

void perror (const char* str)
{
  if ( (str != NULL) && (str[0] != '\n') ) {
    fprintf (stderr, "%s: %s\n", str, strerror(errno) );
  } else {  
    fprintf (stderr, "%s\n", strerror(errno) );
  }
}


