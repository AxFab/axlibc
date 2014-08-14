#include <ax/file.h>
#include <errno.h>

int vfscanf(FILE *restrict f, const char *restrict format, va_list ap)
{
  // FIXME ...
  errno = ENOSYS;
  return -1;
}
