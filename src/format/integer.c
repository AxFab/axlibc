
#define LOWER 0x20

static const char const* digits = 
  "0123456789abcdefghijklmnopqrstuvwxyz";


long strtol (const char* str, char** ptr, int base)
{
  int value = 0;

  if (base == 0) { 
    if (str[0] != '0') {
      base = 10;

    } else if ((str[1] | LOWER) == 'x') {
      base = 16;
      str += 2;

    } else {
      base = 8;
      str++;
    }
  }

  for (;;str++) {

    if (*str < '0' || (*str | LOWER) >= digits[base])
      break;

    value *= base;

    if (*str <= '9')
      value += (*str) - '0';
    else
      value += ((*str) | LOWER) - 'a' + 10;

  }

  if (ptr) (*ptr) = (char*)str;
  return value;
}
