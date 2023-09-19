#include <stdio.h>
#include <stdarg.h>
#include "main.h"
void custom_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%' && *(format + 1) == 'S') {
            format += 2;

            char *str = va_arg(args, char *);
            if (str != NULL) {
                while (*str) {
                    if (*str >= 32 && *str < 127) {
                        putchar(*str);
                    } else {
                        printf("\\x%02X", (unsigned char)*str);
                    }
                    str++;
                }
            }
        } else {
            putchar(*format);
            format++;
        }
    }

    va_end(args);
}

