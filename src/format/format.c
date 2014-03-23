#include <stdint.h>
#include <prv/format.h>

typedef struct xFormat xFormat_t;
struct xFormat 
{
  int     _type;
  int     _size;
  int     (*_pc)(int c, void* d);
  void*   _data;
  int     _cnt;
  int     _width;
};

#define F_DECIMAL_SIGNED  1
#define F_DECIMAL_UNSIGNED  2
#define F_OCTAL_SIGNED  3
#define F_HEXADECIMAL_UNSIGNED  4
#define F_STRING  5
#define F_CHAR  6

int getFormat (const char * str, xFormat_t* frmt, const char **ptr)
{
  switch (str[0]) {
    case '-':
      str++;
      break;
  }

  frmt->_width = strtol(str, (char**)&str, 10);

  frmt->_type = 0;
  switch (str[0]) {
    case 'd':
    case 'i':
      frmt->_type = F_DECIMAL_SIGNED; // decimal signed  
      break;

    case 'o':
      frmt->_type = F_OCTAL_SIGNED; // octal signed 
      break;

    case 'u':
      frmt->_type = F_DECIMAL_UNSIGNED; // decimal unsigned 
      break;

    case 'x':
    case 'X': // Use UPERCASE !
      frmt->_type = F_HEXADECIMAL_UNSIGNED; // hexadecimal unsigned 
      break;

    case 'e':
    case 'E': // Use UPERCASE !
      frmt->_type = 1; // double scientific 
      break;

    case 's':
      frmt->_type = F_STRING; // string 
      break;

    case 'c':
      frmt->_type = F_CHAR;
      break;

    default: break;
  }

  if (frmt->_type != 0) str++;


  if (ptr)
    *ptr = str;

  return 0;
}

#define PUTC(c)   do {                              \
        if (frmt->_pc ((c), frmt->_data) < 0) {     \
          return -1;                                \
        }                                           \
        frmt->_cnt++;                               \
      } while (0)

int frmtString (xFormat_t* frmt, const char* str) 
{
  while (*str) {
    PUTC (*str);
    str++;
  }

  return 0;
}


int frmtDecimal (xFormat_t* frmt, uint32_t value) 
{
  char tstck[24] = { 0 };
  int tpr = 0;

  if (value == 0) {
    PUTC ('0');
    return 0;
  }

  while (value) {
    tstck[tpr++] = (value % 10) + '0';
    value = value / 10;
  }

  while (tpr > 0) {
    PUTC (tstck[--tpr]);
  }

  return 0;
}

int frmtHexadecimal (xFormat_t* frmt, uint32_t value) 
{
  int w = 1;
  int sld = sizeof (uint32_t) * 8 - 4;
  int size = sizeof (uint32_t) * 2; 

  while (size-- > 0) {
    int dg = (value >> sld) & 0xf;
    if (w == 1 || dg != 0) { 
      PUTC (dg < 10 ? dg + '0' : dg - 10 + 'a');
    }

    value = value << 4;
  }

  if (w == 0) PUTC ('0');
  return 0;
}



int format (int (*pc)(int c, void* d), void* data, const char* str, void* args) 
{
  xFormat_t F;
  xFormat_t* frmt = &F;
  frmt->_cnt = 0;
  frmt->_pc = pc;
  frmt->_data = data;

  while (*str) {
    if (*str != '%') {
      PUTC(*str);
      str++;
      continue;
    } 

    if (str[1] == '%') {
      PUTC(*str);
      str+=2;
      continue;
    } 

    str++;
    getFormat (str, frmt, &str);

    switch (frmt->_type) {

      case F_STRING:
        frmtString (frmt, ((char**)args)[0]);
        args = (uint8_t*)args + sizeof (char*);
        break;

      case F_CHAR:
        pc (((int*)args)[0], data);
        args = (uint8_t*)args + sizeof (int);
      break;

      case F_DECIMAL_SIGNED:
        frmtDecimal (frmt, (
            (int*)args)[0]);
        args = (uint8_t*)args + sizeof (int);
        break;

      case F_HEXADECIMAL_UNSIGNED:
        frmtHexadecimal (frmt, ((uint32_t*)args)[0]);
        args = (uint8_t*)args + sizeof (uint32_t);
        break;

        
      default: break;
    }

  } 

  return frmt->_cnt;
}



