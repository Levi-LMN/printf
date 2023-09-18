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

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                case 's':
                case '%':
                    count += handle_cs_percent(format, &args);
                    break;
                case 'u':
                case 'o':
                case 'x':
                case 'X':
                    count += handle_uoxX(format, &args);
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

