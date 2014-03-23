// #include "format.h"


#include <stdio.h>
#include <stdarg.h>

long strtol (const char* str, char** ptr, int base);
int format (int (*pc)(int c, void* d), void* data, const char* str, void* args);

int myPrintf (const char *str, ...)
{
  const char** args = &str;
  return format (putc, stdout, str, ++args);
}

// =========================================

#define TEST(n,e,f)    printf("%-20s   [%s]\n", (n), (e) == (f) ? "\e[32mOk\e[0m" : "\e[31mErr\e[0m" )

int main () 
{
  TEST ("#1", 54, strtol("54", NULL, 0)); 
  TEST ("#2", 76, strtol("76", NULL, 0)); 

  TEST ("#3", 0432, strtol("04329", NULL, 0)); 
  TEST ("#4", 0466, strtol("0466", NULL, 0)); 

  TEST ("#5", 0x4f66, strtol("0x4f66", NULL, 0)); 
  TEST ("#6", 0x1e6cd87a, strtol("0x1e6cd87ag", NULL, 0)); 


  myPrintf ("Hello world !\n");

  return 0; 
}



