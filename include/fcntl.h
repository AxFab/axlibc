#ifndef FCNTL_H__
#define FCNTL_H__

#include <sys/stat.h>
#include <unistd.h>

// ===========================================================================
// Values for cmd used by fcntl()
#define F_DUPFD   1   ///< Duplicate file descriptor.
#define F_GETFD   2   ///< Get file descriptor flags.
#define F_SETFD   3   ///< Set file descriptor flags.
#define F_GETFL   4   ///< Get file status flags and file access modes.
#define F_SETFL   5   ///< Set file status flags.
#define F_GETLK   6   ///< Get record locking information.
#define F_SETLK   7   ///< Set record locking information.
#define F_SETLKW  8   ///< Set record locking information; wait if blocked.

// File descriptor flags used for fcntl()
#define FD_CLOEXEC  0 ///< Close the file descriptor upon execution of an exec family function.

// Values for l_type used for record locking with fcntl()
#define F_RDLCK   0   ///< Shared or read lock.
#define F_UNLCK   1   ///< Unlock.
#define F_WRLCK   2   ///< Exclusive or write lock.


// The following four sets of values for oflag are used by open()
#define O_CREAT     0x40   ///< Create file if it does not exist.
#define O_EXCL      0x80   ///< Exclusive use flag.
#define O_NOCTTY    0x100   ///< Do not assign controlling terminal.
#define O_TRUNC     0x200   ///< Truncate flag.


// File status flags used for open() and fcntl()
#define O_STATMSK   0x101c00

#define O_APPEND    0x000400   ///< Set append mode.
#define O_DSYNC     0x001000   ///< Write according to synchronised I/O data integrity completion.
#define O_NONBLOCK  0x000800   ///< Non-blocking mode.
#define O_RSYNC     0x101000   ///< Synchronised read I/O operations.
#define O_SYNC      0x101000   ///< Write according to synchronised I/O file integrity completion.

// Others
#define O_BINARY    0x200000
#define O_DIRECTORY 0x400000


// Mask for use with file access modes
#define O_ACCMODE   3   ///< Mask for file access modes.

// File access modes used for open() and fcntl()
#define O_RDONLY    0   ///< Open for reading only.
#define O_RDWR      2   ///< Open for reading and writing.
#define O_WRONLY    1   ///< Open for writing only.


// ===========================================================================
// The structure flock describes a file lock.
struct flock {
  short l_type;   ///< type of lock; F_RDLCK, F_WRLCK, F_UNLCK
  short l_whence; ///< flag for starting offset
  off_t l_start;  ///< relative offset in bytes
  off_t l_len;    ///< size; if 0 then until EOF
  pid_t l_pid;    ///< process ID of the process holding the lock; returned with F_GETLK
};

// ===========================================================================
/** Do the file control operation described by CMD on FD.
 *  The remaining arguments are interpreted depending on CMD.
 */
int fcntl(int fd, int cmd, ...);

/** Open FILE and return a new file descriptor for it, or -1 on error.
 *  OFLAG determines the type of access used.  If O_CREAT is on OFLAG,
 *  the third argument is taken as a `mode_t', the mode of the created file.
 */
int open(const char * file, int oflag, ...);

/** Similar to `open' but a relative path name is interpreted relative to
 *  the directory for which FD is a descriptor.
 */
int openat(int fd, const char *file, int oflag, ...);

/** Create and open FILE, with mode MODE.  This takes an `int' MODE
 *  argument because that is what `mode_t' will be widened to.
 */
int creat(const char * file, mode_t mode);

/** Reserve storage for the data of the file associated with FD.
 */
int fallocate (int fd, off_t offset, off_t len);



#endif /* FCNTL_H__ */
