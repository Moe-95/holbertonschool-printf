#include "main.h"
/**
*_strlen - Calculate the length of a string.
*
*@s: Pointer to s.
*Return: Counter.
*/
int _strlen(char *s)
{
int count = 0;
while (*s != '\0')
{
count++;
s++;
}
return (count);
}
