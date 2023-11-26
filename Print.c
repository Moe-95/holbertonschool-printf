#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * _write_char - writes a character to stdout
 * @c: character to write
 * Return: number of characters written
 */
int _write_char(char c)
{
return write(1, &c, 1);
}

/**
* _write_string - writes a string to stdout
* @str: string to write
* Return: number of characters written
*/
int _write_string(char *str)
{
if (str != NULL)
{
int len = write(1, str, strlen(str));
if (len == -1)
{
return -1;
}
return len;
}
else
{
return write(1, "(null)", 6);
}
}

/**
* _write_int - writes an integer to stdout
* @num: integer to write
* Return: number of characters written
*/
int _write_int(int num)
{
char buffer[50];
int len = snprintf(buffer, sizeof(buffer), "%d", num);
return write(1, buffer, len);
}

/**
* _printf - print formatted string.
* @format: format to use.
* Return: number of characters printed
*/
int _printf(const char *format, ...)
{
int count = 0;
if (format == NULL)
{
return write(1, NULL, 1);
}
else
{
va_list args;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += _write_char(va_arg(args, int));
break;
case 's':
count += _write_string(va_arg(args, char *));
break;
case '%':
count += _write_char('%');
break;
case 'd':
case 'i':
count += _write_int(va_arg(args, int));
break;
case '\0':
count = write(1, NULL, 1);
return count;
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
}
