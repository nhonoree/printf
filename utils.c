#include "main.h"

/**
 * itoa - Convert integer to string.
 * @n: The integer to convert.
 * @base: The base for conversion (e.g., 10 for decimal, 16 for hexadecimal).
 * @uppercase: Non-zero if uppercase letters should be used (e.g., for hex).
 * Return: Pointer to the resulting string.
 */
char *itoa(int n, int base, int uppercase)
{
    static char buffer[32];
    char *ptr;
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    int sign = n < 0;

    ptr = &buffer[31];
    *ptr = '\0';
    
    if (n == 0)
    {
        *--ptr = '0';
    }
    else
    {
        unsigned int num = sign ? -n : n;

        while (num)
        {
            *--ptr = digits[num % base];
            num /= base;
        }
        
        if (sign)
        {
            *--ptr = '-';
        }
    }

    return ptr;
}

/**
 * reverse_string - Reverse a string in place.
 * @str: The string to reverse.
 * Return: Pointer to the reversed string.
 */
char *reverse_string(char *str)
{
    char *end = str + strlen(str) - 1;
    char temp;

    while (str < end)
    {
        temp = *str;
        *str++ = *end;
        *end-- = temp;
    }

    return str;
}

/**
 * str_len - Calculate the length of a string.
 * @str: The string to measure.
 * Return: The length of the string.
 */
size_t str_len(const char *str)
{
    const char *s = str;

    while (*s)
        s++;
    return s - str;
}
