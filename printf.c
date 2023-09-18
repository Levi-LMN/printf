#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Print formatted output to stdout.
 * @format: A format string with optional conversion specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (format && *format)
    {
        if (*format == '%')
        {
            format++; /* Move past '%' */
            if (!*format)
                break;
            else if (*format == 'c')
            {
                char c = (char)va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (*format == 's')
            {
                const char *s = va_arg(args, const char*);
                while (s && *s)
                {
                    putchar(*s);
                    s++;
                    count++;
                }
            }
            else if (*format == '%')
            {
                putchar('%');
                count++;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

