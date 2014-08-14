#include <ax/file.h>

// ---------------------------------------------------------------------------
/** Write using a file descriptor */
int _dread (FILE *restrict fp, char* restrict buf, size_t length)
{
  fp->count_ += length;
  return read (fp->fd_, buf, length);
}

// ---------------------------------------------------------------------------
/** Write using a file descriptor */
int _dwrite (FILE *restrict fp, const char* restrict buf, size_t length)
{
  fp->count_ += length;
  return write (fp->fd_, buf, length);
}



// ---------------------------------------------------------------------------
int _fwrite (FILE *restrict fp, const char* restrict buf, size_t length)
{
  if (fp->lbuf_ == 0) {
    fp->count_ += length;
    return write (fp->fd_, buf, length);

  } else {
    // FILL THE BUFFER, IF WE DETECT A \n WE SEND IT
  }
}

