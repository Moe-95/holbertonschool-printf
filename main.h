#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Function prototype for _printf */
int _printf(const char *format, ...);
int _strlen(char *s);
int _write_formatted(const char *format, va_list args);
int _write_int(int num);
int _write_string(const char *str);
int _write_char(char c);

#endif
