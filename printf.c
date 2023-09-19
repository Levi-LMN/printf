#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints formatted output to stdout.
 * @format: A pointer to the format string.
 * 
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format)
    {
        if (*format == '%')
        {
            format++; /* Move past the '%' */
            switch (*format)
            {
                case 'c':
                {
                    char c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's':
                {
                    char *s = va_arg(args, char *);
                    while (*s)
                    {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    /* Handle unsupported conversion specifiers here */
                    break;
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

