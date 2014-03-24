#include <prv/alloc.h>
#include <stdio.h>
#include <stdarg.h>


// =========================================

#define TEST(n,e,f)    printf("%-20s   [%s]\n", (n), (e) == (f) ? "\e[32mOk\e[0m" : "\e[31mErr\e[0m" )

void test_stack () 
{
  void* stack[2048];
  int sp = 0;

  xHeapArea_t heap;
  meminit_r (&heap, malloc (0x80000), 0x80000 - 64);

  stack[sp++] = malloc_r(&heap, 64);
  stack[sp++] = malloc_r(&heap, 64);

  while (sp < 2048 - 4) {

    TEST ("#1", 0, memcorrupt_r (&heap));
    
    stack[sp++] = malloc_r(&heap, 64);
    stack[sp++] = malloc_r(&heap, 48);
    free_r(&heap, stack[sp-3]);

    TEST ("#2", 0, memcorrupt_r (&heap));

    stack[sp-3] = malloc_r(&heap, 64);
    stack[sp++] = malloc_r(&heap, 48);
    stack[sp++] = malloc_r(&heap, 48);

    TEST ("#3", 0, memcorrupt_r (&heap));

    stack[sp-4] = malloc_r(&heap, 64);
    free_r(&heap, stack[sp--]);
    free_r(&heap, stack[sp--]);

    TEST ("#4", 0, memcorrupt_r (&heap));
  }
}
void test_big () {

  xHeapArea_t heap;
  meminit_r (&heap, malloc (0x80000), 0x80000 - 64);

  malloc_r(&heap, 64);
  malloc_r(&heap, 64);
  malloc_r(&heap, 64);
  void* big = malloc_r(&heap, 1024);
  TEST ("#1", 0, memcorrupt_r (&heap));

  malloc_r(&heap, 64);
  malloc_r(&heap, 64);
  free_r (&heap, big);
  TEST ("#2", 0, memcorrupt_r (&heap));

  malloc_r(&heap, 64);
  TEST ("#3", 0, memcorrupt_r (&heap));
}


int kprintf (const char *msg) {
  printf ("%s",msg);
  return 0;
}

int main () 
{

  xHeapArea_t heap;
  meminit_r (&heap, malloc (0x80000), 0x80000 - 64);

  TEST ("#1", 0, memcorrupt_r (&heap));
  malloc_r(&heap, 64);
  TEST ("#2", 0, memcorrupt_r (&heap));

  test_big ();




  return 0; 
}



