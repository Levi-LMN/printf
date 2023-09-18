#include "main.h"

/**
 * _printf - Prints formatted output to stdout.
 *
 * @format: A format string.
 * @...    : A variable number of arguments to be formatted.
 *
 * Returns: The number of characters printed (excluding the null byte used to end
 * output to strings).
 */
int _printf(const char *format, ...)
{
  /**
   * Create a variable argument list to iterate over the arguments.
   */
  va_list args;
  va_start(args, format);

  /**
   * Initialize the number of characters printed.
   */
  int count = 0;

  /**
   * Iterate over the format string and print each character, except for format
   * specifiers. When a format specifier is encountered, print the corresponding
   * argument value.
   */
  while (*format != '\0') {
    if (*format == '%') {
      switch (*(++format)) {
        case 'c':
          count += 1;
          putchar(va_arg(args, int));
          break;
        case 's':
          count += strlen(va_arg(args, char *));
          puts(va_arg(args, char *));
          break;
        case '%':
          count += 1;
          putchar('%');
          break;
        default:
          return -1;
      }
    } else {
      count += 1;
      putchar(*format);
    }
    format++;
  }

  /**
   * Clean up the variable argument list.
   */
  va_end(args);

  /**
   * Return the number of characters printed.
   */
  return count;
}

