#include "main.h"
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024

typedef struct {
    char flags;
    int width;
    int precision;
    char size;
} FormatSpecifier;

void print_buffer(char buffer[], int *buff_ind);
int parse_format(const char *format, va_list args);

int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    va_list args;
    va_start(args, format);

    int printed_chars = parse_format(format, args);

    va_end(args);

    return printed_chars;
}

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, buffer, *buff_ind);
    
    *buff_ind = 0;
}

int parse_format(const char *format, va_list args)
{
    char buffer[BUFF_SIZE];
    int buff_ind = 0;
    int printed_chars = 0;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
            {
                print_buffer(buffer, &buff_ind);
                printed_chars += BUFF_SIZE;
            }
            else
            {
                printed_chars++;
            }
        }
        else
        {
            i++;
        }
    }

    print_buffer(buffer, &buff_ind);
    printed_chars += buff_ind;

    return printed_chars;
}

