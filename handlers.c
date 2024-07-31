#include "main.h"

/**
 * handle_specifier - Directs format specifiers to the appropriate function.
 * @format: Format string.
 * @index: Current index in the format string.
 * @args: Argument list.
 * Return: Number of characters printed.
 */
int handle_specifier(const char *format, int *index, va_list args)
{
    int count = 0;
    int width;

    // Check if there is a width specifier
    if (format[*index] == '*')
    {
        (*index)++;
        width = va_arg(args, int);
    }
    else
    {
        width = get_width(format, index, args);
    }

    switch (format[*index])
    {
        // Handling different format specifiers
        case 'c':
            count += print_char_with_width(va_arg(args, int), width);
            break;
        case 's':
            count += print_string_with_width(va_arg(args, char *), width);
            break;
        case '%':
            count += print_char_with_width('%', width);
            break;
        // Add other cases for different specifiers
        default:
            count += print_char(format[*index]);
            break;
    }

    return count;
}
