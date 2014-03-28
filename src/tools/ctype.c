#include <stdio.h>
#include <ctype.h>

#define CTYPE_ALPHA     0x001
#define CTYPE_BLANK     0x002
#define CTYPE_CNTRL     0x004
#define CTYPE_GRAPH     0x008
#define CTYPE_PUNCT     0x010
#define CTYPE_SPACE     0x020
#define CTYPE_LOWER     0x040
#define CTYPE_UPPER     0x080
#define CTYPE_DIGIT     0x100
#define CTYPE_XDIGT     0x200


int main () {
  
  int i;
  for (i=0; i<128; i++) {

    int s = 0;

    printf ("  { 0x%2x, 0x%2x,", tolower(i), toupper(i) );

    if (iscntrl(i)) {
      printf (" CTYPE_CNTRL");
      s |= CTYPE_CNTRL;
    }

    if (isalpha(i))    {
      printf ("%s CTYPE_ALPHA", (s == 0 ? "" : " |"));
      s |= CTYPE_ALPHA;
    } 

    if (isblank(i))    {
      printf ("%s CTYPE_BLANK", (s == 0 ? "" : " |"));
      s |= CTYPE_BLANK;
    } 

    if (isgraph(i))    {
      printf ("%s CTYPE_GRAPH", (s == 0 ? "" : " |"));
      s |= CTYPE_GRAPH;
    } 
    
    if (ispunct(i))    {
      printf ("%s CTYPE_PUNCT", (s == 0 ? "" : " |"));
      s |= CTYPE_PUNCT;
    } 
    
    if (isspace(i))    {
      printf ("%s CTYPE_SPACE", (s == 0 ? "" : " |"));
      s |= CTYPE_SPACE;
    } 
    
    if (islower(i))    {
      printf ("%s CTYPE_LOWER", (s == 0 ? "" : " |"));
      s |= CTYPE_LOWER;
    } 
    
    if (isupper(i))    {
      printf ("%s CTYPE_UPPER", (s == 0 ? "" : " |"));
      s |= CTYPE_UPPER;
    } 
    
    if (isdigit(i))    {
      printf ("%s CTYPE_DIGIT", (s == 0 ? "" : " |"));
      s |= CTYPE_DIGIT;
    } 
    
    if (isxdigit(i))    {
      printf ("%s CTYPE_XDIGT", (s == 0 ? "" : " |"));
      s |= CTYPE_XDIGT;
    } 

    printf (" },\n");
  }

}


