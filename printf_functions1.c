#include "main.h"

/**
 * print_unsigned - Print an unsigned integer.
 * @n: The unsigned integer to print.
 * Return: Number of characters printed.
 */
int print_unsigned(unsigned int n)
{
    char buffer[11];
    char *str = itoa(n, 10, 0);
    int len = str_len(str);

    return write(1, str, len);
}

/**
 * print_octal - Print an octal number.
 * @n: The unsigned integer to print in octal.
 * Return: Number of characters printed.
 */
int print_octal(unsigned int n)
{
    char buffer[11];
    char *str = itoa(n, 8, 0);
    int len = str_len(str);

    return write(1, str, len);
}

/**
 * print_hex - Print a hexadecimal number.
 * @n: The unsigned integer to print in hexadecimal.
 * @uppercase: Non-zero if uppercase letters should be used.
 * Return: Number of characters printed.
 */
int print_hex(unsigned int n, int uppercase)
{
    char buffer[11];
    char *str = itoa(n, 16, uppercase);
    int len = str_len(str);

    return write(1, str, len);
}
