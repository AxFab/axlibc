#include <string.h>

static char _strerror_tmp[LINE_MAX];

const char* strerror_r ( int err )
{
    if ( err == 0 ) {
        return "No error"; 
    }

    int grp = err & 0x1ff000;
    switch ( grp ) {
        case 0:
        return "Lib error"; 

        default:
            return "Unknown Error";
    }
}

/* Copy error string on the buffer */
void strerror_s ( char* str, size_t length, int err )
{
    strncpy ( str, strerror_r ( err ), length );
}


/* Return error string */
char* strerror ( int err )
{
    return strncpy ( _strerror_tmp, strerror_r ( err ), LINE_MAX );
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




