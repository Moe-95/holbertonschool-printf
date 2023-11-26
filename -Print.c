#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
*write_char - Writes a character to standard output.
*@c: char to write
*Return: Int.
*/
int write_char(char c)
{
return write(1, &c, 1);
}

/**
*write_string - Writes a string to standard output.
*@str: String to write.
*Return: Int.
*/
int write_string(const char *str)
{
return write(1, str, strlen(str));
}

/**
*write_int - Writes an integer to standard output.
*@num: Int to write.
*Return: Int.
*/
int write_int(int num)
{
char buffer[50];
int len = snprintf(buffer, sizeof(buffer), "%d", num);
return write(1, buffer, len);
}

/**
*write_formatte - Writes a formatted string to standard output.
*@format: String format.
*@args: args.
*Return: Int.
*/
int write_formatted(const char *format, va_list args)
{
int count = 0;
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += write_char(va_arg(args, int));
break;
case 's':
count += write_string(va_arg(args, char *));
break;
case '%':
count += write_char('%');
break;
case 'd':
case 'i':
count += write_int(va_arg(args, int));
break;
case '\0':
return count;
default:
count += write_string(format - 1);
}
}
else
{
count += write_char(*format);
}
format++;
}
return count;
}

/**
* _printf - print formatted string.
* @format: format to use.
* Return: Number of characters written (excluding null byte).
*/
int _printf(const char *format, ...)
{
if (format == NULL)
{
write_char(NULL);
return 0;
}
va_list args;
va_start(args, format);
int count = write_formatted(format, args);
va_end(args);
return count;
}
