
#include <sys/io.h>
#include <errno.h>

int StreamOpen (const char *path, int flags, mode_t mode, int* fd);
int StreamClose (int fd);
int StreamDataXchg (int fd, const void *buf, size_t count, size_t* reads, int opt);
int StreamSeek (int fd, off_t offset, int whence, off_t* position);

// #define StreamOpen(p,f,m,d)        __syscall(0x11, p, f, m, d, 0);
// #define StreamClose(d)             __syscall(0x12, d, 0, 0, 0, 0);
// #define StreamDataXchg(d,b,c,s,r)  __syscall(0x13, d, b, c, s, r);
// #define StreamSeek(d,o,w)          __syscall(0x14, d, o, w, 0, 0);

#define SYS_RET(r,f)      \
    do {                  \
      (r) = (f);          \
      if ((r) != 0) {     \
        errno = (r);      \
        return -1;        \
      }                   \
    } while (0)




// ---------------------------------------------------------------------------


int open (const char* path, int flags, int mode) 
{
  int fd;
  int ret;

  SYS_RET ( ret, StreamOpen(path, flags, mode, &fd) );
  return fd;
}

int close (int fd)
{
  int ret;

  SYS_RET ( ret, StreamClose (fd) );
  return 0;
}

ssize_t read (int fd, void *buf, size_t count)
{
  ssize_t sz;
  int ret;

  SYS_RET ( ret, StreamDataXchg (fd, buf, count, &sz, O_RDONLY) );
  return sz;
}

ssize_t write (int fd, void *buf, size_t count)
{  
  ssize_t sz;
  int ret;

  SYS_RET ( ret, StreamDataXchg (fd, buf, count, &sz, O_WRONLY) );
  return sz;
}

off_t lseek(int fd, off_t offset, int whence)
{
  off_t pos;
  int ret;

  SYS_RET ( ret, StreamSeek (fd, offset, whence, &pos) );
  return pos;
}

// ---------------------------------------------------------------------------

