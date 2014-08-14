#include <errno.h>

int _errno;

int* _geterrno() {
  return &_errno;
}
