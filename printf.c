#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++; // Move past '%'
            if (format[i] == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                printed_chars++;
            }
            else if (format[i] == 's')
            {
                char *s = va_arg(args, char *);
                if (s == NULL)
                    s = "(null)";
                for (int j = 0; s[j] != '\0'; j++)
                {
                    write(1, &s[j], 1);
                    printed_chars++;
                }
            }
            else if (format[i] == '%')
            {
                write(1, "%", 1);
                printed_chars++;
            }
            // Add more conversion specifiers if needed
        }
        else
        {
            write(1, &format[i], 1);
            printed_chars++;
        }
    }

    va_end(args);

    return printed_chars;
}

