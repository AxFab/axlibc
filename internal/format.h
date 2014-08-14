#ifndef PRV_FORMAT_H__
#define PRV_FORMAT_H__

#include <stdint.h>
#include <sys/types.h>




uintmax_t _strtox(const char * str, char ** endptr, int base, char* sign);



extern const char* _utoa_digits;
extern const char* _utoa_digitsX;



int atoi (const char* str);
long atol (const char* str);
long long atoll (const char* str);
long strtol (const char * str, char ** endptr, int base);
long long strtoll (const char * str, char ** endptr, int base);
unsigned long strtoul (const char * str, char ** endptr, int base);
unsigned long long strtoull (const char * str, char ** endptr, int base);
char* _utoa (uintmax_t value, char * str, int base, const char* digits);

char* itoa (int value, char * str, int base);


#endif /* PRV_FORMAT_H__ */
