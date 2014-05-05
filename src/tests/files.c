// #include <sys/time.h>
#include <stdio.h>

#define TEST(n,e,f)    \
  printf("%-40s   [%s]\n", (n), (e) == (f) ? "\e[32mOk\e[0m" : "\e[31mErr\e[0m" )


// /* Return 1 if the difference is negative, otherwise 0.  */
// int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
// {
//     long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
//     result->tv_sec = diff / 1000000;
//     result->tv_usec = diff % 1000000;

//     return (diff<0);
// }

// void timeval_print(struct timeval *tv)
// {
//     char buffer[30];
//     time_t curtime;

//     printf("%ld.%06ld", tv->tv_sec, tv->tv_usec);
//     curtime = tv->tv_sec;
//     strftime(buffer, 30, "%m-%d-%Y  %T", localtime(&curtime));
//     printf(" = %s.%06ld\n", buffer, tv->tv_usec);
// }




int main () 
{
  int err;
  size_t sz;
  FILE* fp;

  // struct timeval tvBegin, tvEnd, tvDiff;

  // // begin
  // gettimeofday(&tvBegin, NULL);
  // timeval_print(&tvBegin);

  // CREATE & WRITE ----------------------------------------------------------
  fp = fopen ("bench#1.tmp", "w");
  TEST ("Create & write #1", !fp, 0);

  sz = fwrite ("NCE PAR LYN LAX NYC HTW ", 4, 6, fp);
  TEST ("Create & write #2", sz, 6);

  err = fclose (fp);
  TEST ("Create & write #3", err, 0);


  // FORMAT ------------------------------------------------------------------
  fp = fopen ("bench#2.tmp", "w");
  TEST ("File format #1", !fp, 0);
  
  sz = fprintf (fp, "Characters: %c %c \n", 'a', 65);
  TEST ("File format #2", sz, 17);

  sz = fprintf (fp, "Decimals: %d %ld\n", 1977, 650000L);
  TEST ("File format #3", sz, 22);

  sz = fprintf (fp, "Preceding with blanks: %10d \n", 1977);
  TEST ("File format #4", sz, 35);

  sz = fprintf (fp, "Preceding with zeros: %010d \n", 1977);
  TEST ("File format #5", sz, 34);

  sz = fprintf (fp, "Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
  TEST ("File format #6", sz, 46);

  sz = fprintf (fp, "floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
  TEST ("File format #7", sz, 34);

  sz = fprintf (fp, "Width trick: %*d \n", 5, 10);
  TEST ("File format #8", sz, 20);

  sz = fprintf (fp, "%s \n", "A string");
  TEST ("File format #9", sz, 10);

  err = fclose (fp);
  TEST ("File format #10", err, 0);


  // -------------------------------------------------------------------------

  err = remove ("bench#1.tmp");
  TEST ("Remove #1", err, 0);

  err = remove ("bench#2.tmp");
  TEST ("Remove #2", err, 0);





 // //end
 //  gettimeofday(&tvEnd, NULL);
 //  timeval_print(&tvEnd);

 //  // diff
 //  timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
 //  printf("%ld.%06ld\n", tvDiff.tv_sec, tvDiff.tv_usec);



  return 0;
}

/*
    FOPEN (#3)
    FWRITE
    FSEEK [BEG]
    FWRITE
    FTELL
    FSEEK [MID]
    FWRITE
    FTELL
    FSEEK [AFTER]
    FWRITE
    FTELL
    REWIND
    FPUTC
    FTELL
    FCLOSE

    FOPEN (#4)
    FWRITE
    FFLUSH
    FWRITE
    FFLUSH
    FWRITE
    FCLOSE

    OPEN (#5)
    FILENO
     FDOPEN
    CLOSE
     FWRITE
     FCLOSE

    FOPEN (#6)
    FCLOSE (#6)
    FOPEN (#6)
    FPUTC
    FPUTS
    FCLOSE
    */

    // DELETE, MOVE FILE

    /*
    REMOVE (#3)
    FOPEN (#3)

    RENAME (#6, #3)
    */

    // READ

    // TMPFILE

    // LOCKS - MULTI-THREADS

    // STDIN - STDOUT

    // POPEN



    // RE-OPEN

    // BAD ACCESS

