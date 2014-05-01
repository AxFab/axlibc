#include <stdint.h>
#include <format.h>

typedef struct xFormat xFormat_t;
struct xFormat 
{
  union {
    struct {
      char     _size;
      char     _type;
    };
    uint16_t   _func;
  };
  int     (*_pc)(int c, void* d);
  void*   _data;
  int     _cnt;
  int     _width;
  int     _precision;
};

#define F_DECIMAL_SIGNED  1   // d i
#define F_DECIMAL_UNSIGNED  2 // u o
#define F_OCTAL_SIGNED  3 // o
#define F_HEXADECIMAL_UNSIGNED  4 // x X
#define F_STRING  5 // s
#define F_CHAR  6 // c
#define F_POINTER  7 // p
#define F_COUNTER  8 // n
#define F_DOUBLE 9 // f F e E g G a A (need details)

#define F_SZ_INT 0
#define F_SZ_CHAR 1 // hh
#define F_SZ_SHORT 2 // h
#define F_SZ_LONG 3 // l
#define F_SZ_LLONG 4 // ll
#define F_SZ_INTMAX 5 // j
#define F_SZ_INTSIZ 6 // z
#define F_SZ_INTPTR 7 // t
#define F_SZ_DECIMAL 8 // L

#define F_RN_SGINT    (F_SZ_INT | (F_DECIMAL_SIGNED << 8)) // %d - %i
#define F_RN_SGCHAR   (F_SZ_CHAR | (F_DECIMAL_SIGNED << 8)) // %hhd - %hhi
#define F_RN_SGSHORT  (F_SZ_SHORT | (F_DECIMAL_SIGNED << 8)) // %hd - %hi
#define F_RN_SGLONG   (F_SZ_SHORT | (F_DECIMAL_SIGNED << 8)) // %hd - %hi


int getFormat (const char * str, xFormat_t* frmt, const char **ptr)
{
  // FLAGS (- + ' ' # 0)
  switch (str[0]) {
    case '-':
      // ALIGN LEFT
      str++;
      break;

    case '+':
      // FORCE SIGN +
      str++;
      break;

    case ' ':
      // FORCE SIGN :space:
      str++;
      break;

    case '#':
      // ADD DECORATION (0 0x 0X or deciaml point)
      str++;
      break;

    case '0':
      // PADDING '0'
      str++;
      break;
  }

  // WIDTH (num *)
  if (str[0] == '*') {
  } else 
    frmt->_width = strtol(str, (char**)&str, 10);

  // .PRECISION (num *)
  if (str[0] == '.') {
    str++;
    frmt->_precision = strtol(str, (char**)&str, 10);
  }

  // LENGTH (hh h l ll j z t L)
  frmt->_size = F_SZ_INT;
  switch (str[0]) {
    case 'h':
      if (str[1] == 'h') { 
        frmt->_size = F_SZ_CHAR;
        str += 2;
      } else {
        frmt->_size = F_SZ_SHORT;
        str++;
      }
      break;

    case 'l':
      if (str[1] == 'l') { 
        frmt->_size = F_SZ_LLONG;
        str += 2;
      } else {
        frmt->_size = F_SZ_LONG;
        str++;
      }
      break;

    case 'j':
      frmt->_size = F_SZ_INTMAX;
      str++;
      break;

    case 'z':
      frmt->_size = F_SZ_INTSIZ;
      str++;
      break;

    case 't':
      frmt->_size = F_SZ_INTPTR;
      str++;
      break;

    case 'L':
      frmt->_size = F_SZ_DECIMAL;
      str++;
      break;

    default: break;
  }

  // SPECIFIER (d i u o x X f F e E g G a A c s P n)
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

    case 's':
      frmt->_type = F_STRING; // string 
      break;

    case 'c':
      frmt->_type = F_CHAR;
      break;

    case 'p':
      frmt->_type = F_POINTER;
      break;

    case 'n':
      frmt->_type = F_COUNTER;
      break;

    case 'e':
    case 'E': // Use UPERCASE !
      frmt->_type = F_DOUBLE; // double scientific 
      break;

    default: break;
  }

  if (frmt->_type != 0) str++;
  if (ptr) *ptr = str;
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



