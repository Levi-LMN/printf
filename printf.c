#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Print formatted output to stdout
 * @format: The format string containing conversion specifiers
 *         (supports %c, %s, %d, %i, and %%)
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    int charCount = 0;
    va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;

            if (*format == 'c')
            {
                char c = va_arg(args, int);
                putchar(c);
                charCount++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                while (*str != '\0')
                {
                    putchar(*str);
                    str++;
                    charCount++;
                }
            }
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                printf("%d", num);
                charCount++;
            }
            else if (*format == '%')
            {
                putchar('%');
                charCount++;
            }
        }
        else
        {
            putchar(*format);
            charCount++;
        }
        format++;
    }

    va_end(args);
    return charCount;
}

