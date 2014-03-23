#include <string.h>
#include <stdint.h>

// Copy block of memory
void* memcpy ( void* dest, const void* src, size_t length )
{
  register uint8_t* ptr1 = ( uint8_t* ) dest;
  register const uint8_t* ptr2 = ( const uint8_t* ) src;

  while (length--) {
    *ptr1++ = *ptr2++;
  }

  return dest;
}

// Copy source buffer to destination buffer
void* memmove ( void* dest, const void* src, size_t length )
{
  register uint8_t* ptr1 = ( uint8_t* ) dest;
  register const uint8_t* ptr2 = ( const uint8_t* ) src;

  if ( ptr1 >= ptr2 || ptr1 >= ptr2 + length ) {
    while (length--) {
      *ptr1++ = *ptr2++;
    }
  } else {
    ptr1 += length - 1;
    ptr2 += length - 1;
  
    while (length--) {
      *ptr1-- = *ptr2--;
    }
  }

  return dest;
}

// Compare two blocks of memory
int memcmp ( const void* dest, const void* src, size_t length )
{
  register const uint8_t* ptr1 = ( const uint8_t* ) dest;
  register const uint8_t* ptr2 = ( const uint8_t* ) src;

  while ( --length && *ptr1 == *ptr2 ) {
    ++ptr1;
    ++ptr2;
  }

  return *ptr1 - *ptr2;
}

// Search a character into a block of memory
void* memchr ( const void* ptr, int chr, size_t length )
{
  register const uint8_t* ptr0 = ( const uint8_t* ) ptr;

  while ( length > 0 && ( *ptr0 != ( uint8_t ) chr ) ) {
    ++ptr0;
    --length;
  }

  return ( void* ) ( length ? ptr0 : 0 );
}

// Set all byte of a block of memory to the same value
void* memset ( void* ptr, int val, size_t length )
{
  register uint8_t* org = ( uint8_t* ) ptr;

  while (length--) {
    *org++ = ( uint8_t ) val;
  }

  return ptr;
}


#if defined (__BSD)

void* memccpy (void* __restrict dest, const void* __restrict src, int c, size_t length)
{

}

#endif 

#if defined (__GNU)

void* rawmemchr (const void* ptr, int chr)
{

}

void *memrchr (const void* ptr, int chr, size_t length)
{

}

void *mempcpy (void* __restrict dest, const void* __restrict src, size_t length)
{

}

void* memmem (const void* haystack, size_t haystacklen, const void* needle, size_t needlelen)
{

}

#endif