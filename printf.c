#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
/**
*_printf - print formatted string.
*@format: format to use.
*Return: Always 0.
*/
int _printf(const char *format, ...)
{
int count = 0;
char c;
char *str;
int num, len;
char buffer[20];
va_list args;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%') {
format++;
switch (*format)
{
case 'c':
c = va_arg(args,int);
count += write(1, &c, 1);
break;
case 's':
{
char *str = va_arg(args, char*);
count += write(1, str, _strlen(str));
break;
}
case '%':
count += write(1, "%", 1);
break;
case 'd':
case 'i':
{
num = va_arg(args, int);
len = snprintf(buffer, sizeof(buffer), "%d", num);
count += write(1, buffer, len);
break;
}
default:
count += write(1, format - 1, 2);
}
}
else
{
count += write(1, format, 1);
}
format++;
}

va_end(args);
return count;
}
