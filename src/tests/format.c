// #include "format.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>

long strtol (const char* str, char** ptr, int base);
int format (int (*pc)(int c, void* d), void* data, const char* str, void* args);

// int myPrintf (const char *str, ...)
// {
//   const char** args = &str;
//   return format (putc, stdout, str, ++args);
// }

// ===========================================================================

#define TEST(n,e,f)    \
  printf("%-40s   [%s]\n", (n), (e) == (f) ? "\e[32mOk\e[0m" : "\e[31mErr\e[0m" )

#define TEST_STR(n,e,f)    \
  do { /*printf ("STR: '%s'\n",(e));*/ printf("%-40s   [%s]\n", (n), strcmp((e), (f)) == (0) ? "\e[32mOk\e[0m" : "\e[31mErr\e[0m" ); } while(0)

#define STR_LENGTH 2048


// ===========================================================================


int main () 
{
  char str[STR_LENGTH];

  TEST ("#1", 54, strtol("54", NULL, 0)); 
  TEST ("#2", 76, strtol("76", NULL, 0)); 

  TEST ("#3", 0432, strtol("04329", NULL, 0)); 
  TEST ("#4", 0466, strtol("0466", NULL, 0)); 

  TEST ("#5", 0x4f66, strtol("0x4f66", NULL, 0)); 
  TEST ("#6", 0x1e6cd87a, strtol("0x1e6cd87ag", NULL, 0)); 

  // -------------------------------------------------------------------------
  // -------------------------------------------------------------------------

  snprintf (str, STR_LENGTH, "INTEGER %d|%i|%u|%o|%x|%X|%d", 
    (int)64966,(int)0,(int)-8764,(int)763109,(int)-7,(int)0,(int)73);
  TEST_STR ("Integer type format #1", str, "INTEGER 64966|0|4294958532|2722345|fffffff9|0|73");

  snprintf (str, STR_LENGTH, "INTEGER %d|%i|%u|%o|%x|%X|%d", 
    (int)0,(int)-453435,(int)4654564,(int)0,(int)20306,(int)-9783,(int)89);
  TEST_STR ("Integer type format #2", str, "INTEGER 0|-453435|4654564|0|4f52|FFFFD9C9|89");

  snprintf (str, STR_LENGTH, "INTEGER %d|%i|%u|%o|%x|%X|%d", 
    (int)-87654,(int)36,(int)0,(int)-89900,(int)0,(int)8465,(int)-954);
  TEST_STR ("Integer type format #3", str, "INTEGER -87654|36|0|37777520324|0|2111|-954");

  // -------------------------------------------------------------------------

  snprintf (str, STR_LENGTH, "INTEGER %hhd|%hhi|%hhu|%hho|%hhx|%hhX|%hhd", 
    (int)64966,(int)0,(int)-8764,(int)763109,(int)-7,(int)0,(int)73);
  TEST_STR ("Byte type format #1", str, "INTEGER -58|0|196|345|f9|0|73");

  snprintf (str, STR_LENGTH, "INTEGER %hhd|%hhi|%hhu|%hho|%hhx|%hhX|%hhd", 
    (int)0,(int)-453435,(int)4654564,(int)0,(int)20306,(int)-9783,(int)89);
  TEST_STR ("Byte type format #2", str, "INTEGER 0|-59|228|0|52|C9|89");

  snprintf (str, STR_LENGTH, "INTEGER %hhd|%hhi|%hhu|%hho|%hhx|%hhX|%hhd", 
    (int)-87654,(int)36,(int)0,(int)-89900,(int)0,(int)8465,(int)-954);
  TEST_STR ("Byte type format #3", str, "INTEGER -102|36|0|324|0|11|70");

  // -------------------------------------------------------------------------

  snprintf (str, STR_LENGTH, "INTEGER %hd|%hi|%hu|%ho|%hx|%hX|%hd", 
    (int)64966,(int)0,(int)-8764,(int)763109,(int)-7,(int)0,(int)73);
  TEST_STR ("Short type format #1", str, "INTEGER -570|0|56772|122345|fff9|0|73");

  snprintf (str, STR_LENGTH, "INTEGER %hd|%hi|%hu|%ho|%hx|%hX|%hd", 
    (int)0,(int)-453435,(int)4654564,(int)0,(int)20306,(int)-9783,(int)89);
  TEST_STR ("Short type format #2", str, "INTEGER 0|5317|1508|0|4f52|D9C9|89");

  snprintf (str, STR_LENGTH, "INTEGER %hd|%hi|%hu|%ho|%hx|%hX|%hd", 
    (int)-87654,(int)36,(int)0,(int)-89900,(int)0,(int)8465,(int)-954);
  TEST_STR ("Short type format #3", str, "INTEGER -22118|36|0|120324|0|2111|-954");

  // -------------------------------------------------------------------------

  snprintf (str, STR_LENGTH, "INTEGER %ld|%li|%lu|%lo|%lx|%lX|%ld", 
    (long)0,(long)-8945655463435487,(long)78656434164,(long)0,(long)-815465464,(long)9453,(long)0);
  TEST_STR ("Long type format #1", str, "INTEGER 0|1204921121|1347022836|0|cf64fc08|24ED|0");

  snprintf (str, STR_LENGTH, "INTEGER %ld|%li|%lu|%lo|%lx|%lX|%ld", 
    (long)-97646513213487651,(long)57784116547,(long)0,(long)-57531,(long)4895645313798,(long)0,(long)-84564);
  TEST_STR ("Long type format #2", str, "INTEGER 2052769245|1949541699|0|37777617505|db332b06|0|-84564");

  snprintf (str, STR_LENGTH, "INTEGER %ld|%li|%lu|%lo|%lx|%lX|%ld", 
    (long)74651316,(long)0,(long)-796,(long)32456,(long)0,(long)-789321,(long)87984651231679);
  TEST_STR ("Long type format #3", str, "INTEGER 74651316|0|4294966500|77310|0|FFF3F4B7|-2048794177");

  // -------------------------------------------------------------------------

  snprintf (str, STR_LENGTH, "INTEGER %lld|%lli|%llu|%llo|%llx|%llX|%lld", 
    (long long)0,(long long)-8945655463435487,(long long)78656434164,(long long)0,(long long)-815465464,(long long)9453,(long long)0);
  TEST_STR ("Long long type format #1", str, "INTEGER 0|-8945655463435487|78656434164|0|ffffffffcf64fc08|24ED|0");

  snprintf (str, STR_LENGTH, "INTEGER %lld|%lli|%llu|%llo|%llx|%llX|%lld",
    (long long)-97646513213487651,(long long)57784116547,(long long)0,(long long)-57531,(long long)4895645313798,(long long)0,(long long)-84564);
  TEST_STR ("Long long type format #2", str, "INTEGER -97646513213487651|57784116547|0|1777777777777777617505|473db332b06|0|-84564");

  snprintf (str, STR_LENGTH, "INTEGER %lld|%lli|%llu|%llo|%llx|%llX|%lld",
    (long long)74651316,(long long)0,(long long)-796,(long long)32456,(long long)0,(long long)-789321,(long long)87984651231679);
  TEST_STR ("Long long type format #3", str, "INTEGER 74651316|0|18446744073709550820|77310|0|FFFFFFFFFFF3F4B7|87984651231679");

  // -------------------------------------------------------------------------

  snprintf (str, STR_LENGTH, "INTEGER %jd|%ji|%ju|%jo|%jx|%jX|%jd", 
    (intmax_t)0,(intmax_t)-8945655463435487,(intmax_t)78656434164,(intmax_t)0,(intmax_t)-815465464,(intmax_t)9453,(intmax_t)0);
  TEST_STR ("IntMax type format #1", str, "INTEGER 0|-8945655463435487|78656434164|0|ffffffffcf64fc08|24ED|0");

  snprintf (str, STR_LENGTH, "INTEGER %jd|%ji|%ju|%jo|%jx|%jX|%jd",
    (intmax_t)-97646513213487651,(intmax_t)57784116547,(intmax_t)0,(intmax_t)-57531,(intmax_t)4895645313798,(intmax_t)0,(intmax_t)-84564);
  TEST_STR ("IntMax type format #2", str, "INTEGER -97646513213487651|57784116547|0|1777777777777777617505|473db332b06|0|-84564");

  snprintf (str, STR_LENGTH, "INTEGER %jd|%ji|%ju|%jo|%jx|%jX|%jd", 
    (intmax_t)74651316,(intmax_t)0,(intmax_t)-796,(intmax_t)32456,(intmax_t)0,(intmax_t)-789321,(intmax_t)87984651231679);
  TEST_STR ("IntMax type format #3", str, "INTEGER 74651316|0|18446744073709550820|77310|0|FFFFFFFFFFF3F4B7|87984651231679");

  // -------------------------------------------------------------------------

  snprintf (str, STR_LENGTH, "INTEGER %zd|%zi|%zu|%zo|%zx|%zX|%zd", 
    (size_t)0,(size_t)-8945655463435487,(size_t)78656434164,(size_t)0,(size_t)-815465464,(size_t)9453,(size_t)0);
  TEST_STR ("IntSize type format #1", str, "INTEGER 0|1204921121|1347022836|0|cf64fc08|24ED|0");

  snprintf (str, STR_LENGTH, "INTEGER %zd|%zi|%zu|%zo|%zx|%zX|%zd", 
    (size_t)-97646513213487651,(size_t)57784116547,(size_t)0,(size_t)-57531,(size_t)4895645313798,(size_t)0,(size_t)-84564);
  TEST_STR ("IntSize type format #2", str, "INTEGER 2052769245|1949541699|0|37777617505|db332b06|0|-84564");

  snprintf (str, STR_LENGTH, "INTEGER %zd|%zi|%zu|%zo|%zx|%zX|%zd", 
    (size_t)74651316,(size_t)0,(size_t)-796,(size_t)32456,(size_t)0,(size_t)-789321,(size_t)87984651231679);
  TEST_STR ("IntSize type format #3", str, "INTEGER 74651316|0|4294966500|77310|0|FFF3F4B7|-2048794177");

  // -------------------------------------------------------------------------

  snprintf (str, STR_LENGTH, "INTEGER %td|%ti|%tu|%to|%tx|%tX|%td",
    (intptr_t)0,(intptr_t)-8945655463435487,(intptr_t)78656434164,(intptr_t)0,(intptr_t)-815465464,(intptr_t)9453,(intptr_t)0);
  TEST_STR ("IntPtr type format #1", str, "INTEGER 0|1204921121|1347022836|0|cf64fc08|24ED|0");

  snprintf (str, STR_LENGTH, "INTEGER %td|%ti|%tu|%to|%tx|%tX|%td", 
    (intptr_t)-97646513213487651,(intptr_t)57784116547,(intptr_t)0,(intptr_t)-57531,(intptr_t)4895645313798,(intptr_t)0,(intptr_t)-84564);
  TEST_STR ("IntPtr type format #2", str, "INTEGER 2052769245|1949541699|0|37777617505|db332b06|0|-84564");

  snprintf (str, STR_LENGTH, "INTEGER %td|%ti|%tu|%to|%tx|%tX|%td", 
    (intptr_t)74651316,(intptr_t)0,(intptr_t)-796,(intptr_t)32456,(intptr_t)0,(intptr_t)-789321,(intptr_t)87984651231679);
  TEST_STR ("IntPtr type format #3", str, "INTEGER 74651316|0|4294966500|77310|0|FFF3F4B7|-2048794177");

  // -------------------------------------------------------------------------

  snprintf (str, STR_LENGTH, "FLOAT %f|%F|%e|%E|%g|%G|%a|%A");
  TEST_STR ("Double type format #1", str, "");

  snprintf (str, STR_LENGTH, "FLOAT %f|%F|%e|%E|%g|%G|%a|%A");
  TEST_STR ("Double type format #2", str, "");

  snprintf (str, STR_LENGTH, "FLOAT %f|%F|%e|%E|%g|%G|%a|%A");
  TEST_STR ("Double type format #3", str, "");


  // -------------------------------------------------------------------------

  snprintf (str, STR_LENGTH, "FLOAT %Lf|%LF|%Le|%LE|%Lg|%LG|%La|%LA");
  TEST_STR ("Decimal type format #1", str, "");

  snprintf (str, STR_LENGTH, "FLOAT %Lf|%LF|%Le|%LE|%Lg|%LG|%La|%LA");
  TEST_STR ("Decimal type format #2", str, "");

  snprintf (str, STR_LENGTH, "FLOAT %Lf|%LF|%Le|%LE|%Lg|%LG|%La|%LA");
  TEST_STR ("Decimal type format #3", str, "");

  // -------------------------------------------------------------------------

  snprintf (str, STR_LENGTH, "CHARS %c|%c|%c|%s|%s|%s", (char)'c', (char)32, (char)48, "Hello world", "", "c library");
  TEST_STR ("Character type format #1", str, "CHARS c| |0|Hello world||c library");

  snprintf (str, STR_LENGTH, "CHARS %lc|%lc|%lc|%ls|%ls|%ls", (char)'c', (char)0xc9, (char)87546, "Hello world", "", "c library");
  TEST_STR ("Wide character type format #1", str, "");

  snprintf (str, STR_LENGTH, "POINTER %p|%p|%p|%p|%p", 
    (void*)0x12345678, (void*)0, (void*)0xccccccc, (void*)46846464, (void*)0xaf1268465);
  TEST_STR ("Pointer type format #1", str, "POINTER 0x12345678|(nil)|0xccccccc|0x2cad200|0xf1268465");

  // -------------------------------------------------------------------------



  // PRINTF

    // TRY EACH TYPE
      // d i u o x X
      // hhd hhi hhu hho hhx hhX
      // hd hi hu ho hx hX
      // ld li lu lo lx lX
      // lld lli llu llo llx llX
      // jd ji ju jo jx jX
      // zd zi zu zo zx zX
      // td ti tu to tx tX
      // f F e E g G a A
      // Lf LF Le LE Lg LG La LA
      //  c s lc ls p

    // TRY EACH TYPE WITH LOWER AND UPPER WIDTH

    // TRY EACH TYPE WITH PRESICION

    // TRY EACH TYPE WITH PRESICION AND WIDTH

    // TRY EACH TYPE WITH FLAGS (+- #0)

    // TRY EACH TYPE WITH FLAGS AND WIDTH (+- #0)


  // sscanf ("INTEGER", 4654564,484894,464,54641,4981,6414,6414,9164,64186,146);
  // TEST_STR ('Integer type scan #1', str, "");

  return 0; 
}



