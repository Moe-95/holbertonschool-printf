#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Function prototype for _printf */
int _printf(const char *format, ...);
int _strlen(char *s);
int write_formatted(const char *format, va_list args);
int write_int(int num);
int write_string(const char *str);
int write_char(char c);

#endif
