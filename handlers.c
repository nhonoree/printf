#include "main.h"

/**
 * handle_specifier - Directs format specifiers to the appropriate function.
 * @format: Format string.
 * @index: Current index in the format string.
 * @args: Argument list.
 * Return: Number of characters printed.
 */
int handle_specifier(const char *format, int index, va_list args)
{
    int count = 0;

    switch (format[index])
    {
        case 'c':
            count += print_char(va_arg(args, int));
            break;
        case 's':
            count += print_string(va_arg(args, char *));
            break;
        case '%':
            count += print_char('%');
            break;
        case 'd':
        case 'i':
            count += print_number(va_arg(args, int));
            break;
        case 'b':
            count += print_binary(va_arg(args, unsigned int));
            break;
        case 'u':
            count += print_unsigned(va_arg(args, unsigned int));
            break;
        case 'o':
            count += print_octal(va_arg(args, unsigned int));
            break;
        case 'x':
            count += print_hex(va_arg(args, unsigned int), 0);
            break;
        case 'X':
            count += print_hex(va_arg(args, unsigned int), 1);
            break;
        case 'S':
            count += print_nonprintable(va_arg(args, char *));
            break;
        case 'p':
            count += print_pointer(va_arg(args, void *));
            break;
        case 'r':
            count += print_reverse(va_arg(args, char *));
            break;
        case 'R':
            count += print_rot13(va_arg(args, char *));
            break;
        default:
            count += print_char(format[index]);
            break;
    }

    return count;
}

/**
 * print_nonprintable - Print a string with non-printable characters.
 * @str: The string to print.
 * Return: Number of characters printed.
 */
int print_nonprintable(const char *str)
{
    char buffer[1024];
    int count = 0;

    if (str == NULL)
        return write(1, "(null)", 6);

    while (*str)
    {
        if (*str < 32 || *str >= 127)
            count += snprintf(buffer + count, sizeof(buffer) - count, "\\x%02X", (unsigned char)*str);
        else
            buffer[count++] = *str;
        str++;
    }

    return write(1, buffer, count);
}

/**
 * print_pointer - Print a pointer address.
 * @ptr: The pointer to print.
 * Return: Number of characters printed.
 */
int print_pointer(void *ptr)
{
    unsigned long addr = (unsigned long)ptr;
    char buffer[20];
    int len;

    len = snprintf(buffer, sizeof(buffer), "0x%lx", addr);

    return write(1, buffer, len);
}
