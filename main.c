#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "World");
    _printf("Number: %u\n", 12345);
    _printf("Octal: %o\n", 12345);
    _printf("Hexadecimal (lowercase): %x\n", 12345);
    _printf("Hexadecimal (uppercase): %X\n", 12345);
    return (0);
}

