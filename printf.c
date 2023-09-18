#include <stdio.h>
#include <stdarg.h>
#include "main.h"

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
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                printf("%d", num);
                count++;
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

