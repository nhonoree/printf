#include "main.h"

int main(void)
{
    _printf("Hello, World!\n");
    _printf("Number: %d\n", 123);
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Sample string");
    _printf("Binary: %b\n", 255);
    _printf("Unsigned: %u\n", 123456);
    _printf("Octal: %o\n", 64);
    _printf("Hex: %x\n", 255);
    _printf("Hex (uppercase): %X\n", 255);
    _printf("Reverse: %r\n", "Hello");
    _printf("Rot13: %R\n", "Hello");

    return 0;
}
