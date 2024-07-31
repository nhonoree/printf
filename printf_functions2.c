#include "main.h"

/**
 * print_binary - Print a binary number.
 * @n: The unsigned integer to print in binary.
 * Return: Number of characters printed.
 */
int print_binary(unsigned int n)
{
    char buffer[33];
    char *str = itoa(n, 2, 0);
    int len = str_len(str);

    return write(1, str, len);
}

/**
 * print_reverse - Print a reversed string.
 * @str: The string to reverse.
 * Return: Number of characters printed.
 */
int print_reverse(const char *str)
{
    char *reversed = strdup(str);
    reverse_string(reversed);
    int len = write(1, reversed, str_len(reversed));
    free(reversed);

    return len;
}

/**
 * print_rot13 - Print a string encoded with rot13.
 * @str: The string to encode.
 * Return: Number of characters printed.
 */
int print_rot13(const char *str)
{
    char buffer[1024];
    int len = 0;

    while (*str)
    {
        char c = *str++;
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            char base = (c >= 'A' && c <= 'Z') ? 'A' : 'a';
            c = (c - base + 13) % 26 + base;
        }
        buffer[len++] = c;
    }

    return write(1, buffer, len);
}
