#include <stdio.h>
#include <stdarg.h>
#include "main.h"
void custom_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%' && *(format + 1) == 'p') {
            format += 2; // Advance past %p

            void *ptr = va_arg(args, void *);
            printf("%p", ptr);
        } else {
            putchar(*format);
            format++;
        }
    }

    va_end(args);
}

