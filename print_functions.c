#include "main.h"

/**
 * print_char - Print a character.
 * @c: The character to print.
 * Return: Number of characters printed.
 */
int print_char(char c)
{
    return write(1, &c, 1);
}

/**
 * print_string - Print a string.
 * @str: The string to print.
 * Return: Number of characters printed.
 */
int print_string(const char *str)
{
    if (str == NULL)
        return write(1, "(null)", 6);

    return write(1, str, str_len(str));
}

/**
 * print_number - Print an integer.
 * @n: The integer to print.
 * Return: Number of characters printed.
 */
int print_number(int n)
{
    char buffer[12];
    char *str = itoa(n, 10, 0);
    int len = str_len(str);

    return write(1, str, len);
}
