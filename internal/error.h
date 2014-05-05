#ifndef _ERROR_H__
#define _ERROR_H__

#include <errno.h>

// int __seterrno(int err);
// int __geterrno();
// int __noerror();


extern int _errno;

static inline int __noerror() 
{
  _errno = 0;
  return 0;
}

static inline int __seterrno(int err) 
{
  _errno = err;
  return err;
}

static inline int __geterrno() 
{
  return _errno;
}




#endif /* _ERROR_H__ */
