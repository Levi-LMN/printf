#include "main.h"

/**
 * handle_uoxX - Handle 'u', 'o', 'x', and 'X' conversion specifiers
 * @format: The conversion specifier
 * @args: The argument list
 *
 * Return: The number of characters printed
 */
int handle_uoxX(const char *format, va_list *args)
{
    unsigned int num;
    char buffer[33];
    int count = 0;

    num = va_arg(*args, unsigned int);

    switch (*format)
    {
        case 'u':
            sprintf(buffer, "%u", num);
            break;
        case 'o':
            sprintf(buffer, "%o", num);
            break;
        case 'x':
            sprintf(buffer, "%x", num);
            break;
        case 'X':
            sprintf(buffer, "%X", num);
            break;
    }

    fputs(buffer, stdout);
    count += strlen(buffer);

    return (count);
}

