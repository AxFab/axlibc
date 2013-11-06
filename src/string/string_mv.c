#include <string.h>

// Copy a null-terminated char string
char* strcpy ( char* dest, const char* src )
{
    register char* ptr1 = ( char* ) dest;
    register const char* ptr2 = ( const char* ) src;

    while ( ( *ptr1++ = *ptr2++ ) );

    return dest;
}

// Copy a char string
char* strncpy ( char* dest, const char* src, size_t length )
{
    register char* ptr1 = ( char* ) dest;
    register const char* ptr2 = ( const char* ) src;

    while ( length-- > 0 && ( *ptr1++ = *ptr2++ ) );

    return dest;
}

// Concat two null-terminated char strings
char* strcat ( char* dest, const char* src )
{
    register char* ptr1 = ( char* ) dest;
    register const char* ptr2 = ( const char* ) src;

    while ( *ptr1 ) {
        ++ptr1;
    }

    while ( ( *ptr1++ = *ptr2++ ) );

    return dest;
}

// Concat two null-terminated char strings
char* strncat ( char* dest, const char* src, size_t length )
{
    register char* ptr1 = ( char* ) dest;
    register const char* ptr2 = ( const char* ) src;

    while ( *ptr1 ) {
        ++ptr1;
    }

    while ( length-- > 0 && ( *ptr1++ = *ptr2++ ) );

    return dest;
}

// Compare two null-terminated char strings
int strcmp ( const char* str1, const char* str2 )
{
    while ( *str1 && ( *str1 == *str2 ) ) {
        ++str1;
        ++str2;
    }

    return *str1 - *str2;
}

// Compare two char strings
int strncmp ( const char* str1, const char* str2, size_t length )
{
    while ( --length && *str1 && *str1 == *str2 ) {
        ++str1;
        ++str2;
    }

    return *str1 - *str2;
}

/*=========================================================
    Locale wierd functions - to re-make TODO
//=======================================================*/

// Collate locale strings (is str2 start by str1)
int strcoll ( char* str1, const char* str2 )
{
    while ( *str1 == *str2++ )
        if ( *str1++ == '\0' ) {
            return 0;
        }

    return *str1 - *--str2;
}

// Transform a string using locale information
size_t strxfrm ( char* str1, const char* str2, size_t length )
{
    register const char* stro = str2;

    while ( *str2 ) {
        if ( length > 1 ) {
            length--;
            *str1++ = *str2++;
        } else {
            str2++;
        }
    }

    if ( length > 0 ) {
        *str1++ = '\0';
    }

    return str2 - stro;
}

