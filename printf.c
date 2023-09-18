#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - A function that produces output according to a format
 * @format: A string that contains the text to be written to stdout
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char* str;
    char c;
    unsigned int num;
    char bin[33];
    char* p;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                case 's':
                    str = va_arg(args, char*);
                    while(*str)
                    {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                case 'b':
                    num = va_arg(args, unsigned int);
                    p = &bin[32];
                    *p = '\0';
                    do {
                        --p;
                        *p = (num & 1) ? '1' : '0';
                        num >>= 1;
                    } while(num != 0);
                    while(*p)
                    {
                        putchar(*p);
                        p++;
                        count++;
                    }
                    break;
                default:
                    return (-1);
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

    return (count);
}

