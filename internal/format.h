#ifndef PRV_FORMAT_H__
#define PRV_FORMAT_H__

typedef int (*_putc_f)(int c, void* d);

int format (_putc_f pc, void* data, const char* str, void* args);

long strtol (const char* str, char** ptr, int base);


#endif /* PRV_FORMAT_H__ */
