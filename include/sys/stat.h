#ifndef SYS_STAT_H__
#define SYS_STAT_H__

#include <sys/types.h>

#define S_IRUSR     (0400)
#define S_IWUSR     (0200)
#define S_IXUSR     (0100)
#define S_IRWXU     (S_IRUSR | S_IWUSR | S_IXUSR)
#define S_IRGRP     (S_IRUSR >> 3)
#define S_IWGRP     (S_IWGRP >> 3)
#define S_IXGRP     (S_IXGRP >> 3)
#define S_IRWXG     (S_IRWXU >> 3)
#define S_IROTH     (S_IRGRP >> 3)
#define S_IWOTH     (S_IWGRP >> 3)
#define S_IXOTH     (S_IXOTH >> 3)
#define S_IRWXO     (S_IRWXG >> 3)

#define S_ISUID     (01000)
#define S_ISGID     (02000)
#define S_ISVTX     (04000)

#define S_IALLUGO   (0777)


#define S_IFREG     (1 << 16)
#define S_IFDIR     (2 << 16)
#define S_IFLNK     (3 << 16)
#define S_IFBLK     (4 << 16)
#define S_IFCHR     (5 << 16)
#define S_IFIFO     (6 << 16)
#define S_IFSOCK    (7 << 16)
#define S_IFMT      (0xff << 16)

#define S_ISBLK(m)    (((m) & S_IFMT) == S_IFBLK)
#define S_ISCHR(m)    (((m) & S_IFMT) == S_IFCHR)
#define S_ISDIR(m)    (((m) & S_IFMT) == S_IFDIR)
#define S_ISFIFO(m)   (((m) & S_IFMT) == S_IFIFO)
#define S_ISREG(m)    (((m) & S_IFMT) == S_IFREG)
#define S_ISLNK(m)    (((m) & S_IFMT) == S_IFLNK)
#define S_ISSOCK(m)   (((m) & S_IFMT) == S_IFSOCK)


#define S_TYPEISMQ(buf)  (S_ISFIFO(buf->st_mode) && 1)  ///< Test for a message queue 
#define S_TYPEISSEM(buf) (S_ISFIFO(buf->st_mode) && 1)  ///< Test for a semaphore
#define S_TYPEISSHM(buf) (S_ISFIFO(buf->st_mode) && 1)  ///< Test for a shared memory object 


struct stat {

  dev_t     st_dev;     ///<  ID of device containing file
  ino_t     st_ino;     ///<  file serial number
  mode_t    st_mode;    ///<  mode of file (see below)
  nlink_t   st_nlink;   ///<  number of links to the file
  uid_t     st_uid;     ///<  user ID of file
  gid_t     st_gid;     ///<   group ID of file
  dev_t     st_rdev;    ///<  device ID (if file is character or block special)
  off_t     st_size;    ///<   file size in bytes (if file is a regular file)
  time_t    st_atime;   ///<  time of last access
  time_t    st_mtime;   ///<   time of last data modification
  time_t    st_ctime;   ///<  time of last status change
  blksize_t st_blksize; ///< a filesystem-specific preferred I/O block size for this object.
  blkcnt_t  st_blocks;  ///< number of blocks allocated for this object

};


int    chmod(const char *, mode_t);
int    fchmod(int, mode_t);
int    fstat(int, struct stat *);
int    lstat(const char *, struct stat *);
int    mkdir(const char *, mode_t);
int    mkfifo(const char *, mode_t);
int    mknod(const char *, mode_t, dev_t);
int    stat(const char *, struct stat *);
mode_t umask(mode_t);




#endif /* SYS_STAT_H__ */
