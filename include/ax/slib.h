#ifndef AX_SLIB_H__
#define AX_SLIB_H__

#include <stdint.h>


extern const char* _utoa_digits;
extern const char* _utoa_digitsX;

uintmax_t _strtox(const char * str, char ** endptr, int base, char* sign);
char* _utoa (uintmax_t value, char* str, int base, const char* digits);


#endif /* AX_SLIB_H__ */
