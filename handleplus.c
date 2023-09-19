#include <stdio.h>
#include <stdarg.h>
#include "main.h"
void custom_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++; /* Skip '%' */

            /* Initialize flags */
            int flag_plus = 0; /* '+' flag */
            int flag_space = 0; /* ' ' flag */
            int flag_alternate = 0; /* '#' flag */

            /* Process flags */
            while (*format == '+' || *format == ' ' || *format == '#') {
                if (*format == '+') {
                    flag_plus = 1;
                } else if (*format == ' ') {
                    flag_space = 1;
                } else if (*format == '#') {
                    flag_alternate = 1;
                }
                format++;
            }

            /* Process the conversion specifier */
            if (*format == 'd' || *format == 'i') {
                int value = va_arg(args, int);
                if (flag_plus && value >= 0) {
                    putchar('+');
                } else if (flag_space && value >= 0) {
                    putchar(' ');
                }
                printf("%d", value);
            } else if (*format == 'o' && flag_alternate) {
                unsigned int value = va_arg(args, unsigned int);
                printf("0%o", value);
            } else if (*format == 'x' && flag_alternate) {
                unsigned int value = va_arg(args, unsigned int);
                printf("0x%x", value);
            } else {
                putchar('%');
                while (*format != '\0' && *format != ' ') {
                    putchar(*format);
                    format++;
                }
                continue;
            }
        } else {
            putchar(*format);
            format++;
        }
    }

    va_end(args);
}

