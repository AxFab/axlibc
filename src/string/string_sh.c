#include <string.h>

// Search a string for a character
char* strchr (const char* string, int ch)
{
    while (*string) {
        if (*string == (char) ch) {
            return (char*) string;
        }

        string++;
    }

    return NULL;
}

// Split string into tokens - reentrent (TODO suppress goto and that is not the best way)
char* strtok_r ( register char* s, register const char* delim, char** lasts )
{
    int skip_leading_delim = 1;
    register char* spanp;
    register int c, sc;
    char* tok;

    if ( s == NULL && ( s = *lasts ) == NULL ) {
        return NULL;
    }

    /*
     * Skip (span) leading delimiters (s += strspn(s, delim), sort of).
     */
cont:
    c = *s++;

    for ( spanp = ( char* ) delim; ( sc = *spanp++ ) != 0; ) {
        if ( c == sc ) {
            if ( skip_leading_delim ) {
                goto cont;
            } else {
                *lasts = s;
                s[-1] = 0;
                return ( s - 1 );
            }
        }
    }

    if ( c == 0 ) {      /* no non-delimiter characters */
        *lasts = NULL;
        return NULL;
    }

    tok = s - 1;

    /*
     * Scan token (scan for delimiters: s += strcspn(s, delim), sort of).
     * Note that delim must have one NUL; we stop if we see that, too.
     */
    for ( ;; ) {
        c = *s++;
        spanp = ( char* ) delim;

        do {
            if ( ( sc = *spanp++ ) == c ) {
                if ( c == 0 ) {
                    s = NULL;
                } else {
                    s[-1] = 0;
                }

                *lasts = s;
                return ( tok );
            }
        } while ( sc != 0 );
    }

    /* NOTREACHED */
}

static char* strtok_reent = 0;

// Split string into tokens
char* strtok ( register char* string , register const char* delimitors )
{
    return strtok_r ( string, delimitors, &strtok_reent );
}

