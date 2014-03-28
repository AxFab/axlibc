
typedef size_t ssize_t;

typedef long gid_t;
typedef long uid_t;
typedef long pid_t;


typedef unsigned long off_t;

#ifdef _IO_EXT
typedef unsigned long off64_t;
#endif

typedef unsigned long useconds_t;



#if defined(__BSD) || defined(__XOPN)
typedef __socklen_t socklen_t;
#endif



int open (const char* file, int oflags, int mode);

int access (const char* name, int type);

off_t lseek (int fd, off_t offset, int whence);

int close (int fd);

ssize_t read (int fd, void* buf, size_t nbytes);
ssize_t write (int fd, void* buf, size_t nbytes);

#ifdef _IO_EXT
off64_t lseek64 (int fd, off64_t offset, int whence);
#endif
