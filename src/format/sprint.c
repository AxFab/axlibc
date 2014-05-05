#include <stdio.h>
#include <format.h>

typedef struct xStrBuild xStrBuild_t;
struct xStrBuild 
{
  char*   buf_;
  int     curs_;
  int     limit_;
};


int strPutc (int c, xStrBuild_t* sb)
{
  if (sb->curs_+1 >= sb->limit_)
    return -1;
  sb->buf_ [ sb->curs_++] = c;
  return 0;
}

int snprintf (char* buf, size_t limit, const char* str, ...) 
{
  const char** args = &str;
  xStrBuild_t sb;
  sb.curs_ = 0;
  sb.buf_ = buf;
  sb.limit_ = limit;
  int res = format ((_putc_f)strPutc, &sb, str, ++args);
  sb.buf_ [ sb.curs_++] = 0;
  return res;
}

int sprintf (char* buf, const char* str, ...) 
{
  const char** args = &str;
  xStrBuild_t sb;
  sb.curs_ = 0;
  sb.buf_ = buf;
  sb.limit_ = INT_MAX;
  int res = format ((_putc_f)strPutc, &sb, str, ++args);
  sb.buf_ [ sb.curs_++] = 0;
  return res;
}


