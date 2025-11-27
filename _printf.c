#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'd' || *format == 'i')
{
int n = va_arg(args, int);
}

}
else
{
write(1, format, 1);
count++;
}
format++;
}
va_end(args);
return count;
}
