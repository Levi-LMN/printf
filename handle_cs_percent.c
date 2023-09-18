#include "main.h"

/**
 * handle_cs_percent - Handle 'c', 's', and '%' conversion specifiers
 * @format: The conversion specifier
 * @args: The argument list
 *
 * Return: The number of characters printed
 */
int handle_cs_percent(const char *format, va_list *args)
{
    char c;
    char* str;
    int count = 0;

    switch (*format)
    {
        case 'c':
            c = va_arg(*args, int);
            putchar(c);
            count++;
            break;
        case 's':
            str = va_arg(*args, char*);
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
    }

    return (count);
}

