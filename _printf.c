#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
va_list args;
int count = 0;
int i, j;
char buf[12];
unsigned int num;
int neg;

if (format == NULL)
return (-1);

va_start(args, format);

i = 0;
while (format[i] != '\0')
{
if (format[i] == '%')
{
i++;
if (format[i] == 'd' || format[i] == 'i')
{
int n = va_arg(args, int);
neg = 0;
if (n < 0)
{
neg = 1;
num = (unsigned int)(-n);
}
else
{
num = (unsigned int)n;
}
j = 0;
if (num == 0)
{
buf[j++] = '0';
}
else
{
while (num > 0 && j < 11)
{
buf[j++] = (num % 10) + '0';
num = num / 10;
}
}
if (neg)
count += write(1, "-", 1);
while (j > 0)
{
count += write(1, &buf[j - 1], 1);
j--;
}
}
else if (format[i] == 'c')
{
char c = (char)va_arg(args, int);
count += write(1, &c, 1);
}
else if (format[i] == 's')
{
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
for (j = 0; str[j] != '\0'; j++)
count += write(1, &str[j], 1);
}
else if (format[i] == '%')
{
count += write(1, "%", 1);
}
else
{
count += write(1, "%", 1);
count += write(1, &format[i], 1);
}
}
else
{
count += write(1, &format[i], 1);
}
i++;
}

va_end(args);
return (count);
}
