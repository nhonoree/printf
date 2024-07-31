#include "main.h"

/**
 * get_width - Extracts the width from the format string.
 * @format: Format string.
 * @index: Current index in the format string.
 * @args: Argument list (if width is specified as a dynamic value).
 * Return: The width value.
 */
int get_width(const char *format, int *index, va_list args)
{
    int width = 0;

    while (format[*index] >= '0' && format[*index] <= '9')
    {
        width = width * 10 + (format[*index] - '0');
        (*index)++;
    }

    if (format[*index] == '*')
    {
        (*index)++;
        width = va_arg(args, int);
    }

    return width;
}
