#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Print formatted output to stdout
 * @format: The format string containing conversion specifiers
 *         (supports %c, %s, and %%)
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int charCount = 0;

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

/**
 * main - Entry point of the program
 * Return: Always 0 (Success)
 */
int main(void)
{
    int count = _printf("Hello, %c World! %s\n", 'C', "C Programming");
    printf("Number of characters printed: %d\n", count);
    return (0);
}

