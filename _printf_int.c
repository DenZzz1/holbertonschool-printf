#include "main.h"

/**
 * print_int - prints a signed integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_int(int n)
{
unsigned int num;
int count = 0;

if (n < 0)
{
count += write(1, "-", 1);
num = (unsigned int)(-n);
}
else
{
num = (unsigned int)n;
}

if (num >= 10)
count += print_int(num / 10);

count += write(1, &"0123456789"[num % 10], 1);

return (count);
}
