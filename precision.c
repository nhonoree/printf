#include "main.h"

/**
 * handle_precision - Process precision specifier for conversion.
 * @format: Format string.
 * @index: Current index in the format string.
 * @args: Argument list.
 * Return: Number of characters printed.
 */
int handle_precision(const char *format, int index, va_list args)
{
    int precision = 0;
    /* Extract precision value from format string */
    while (format[index] >= '0' && format[index] <= '9')
    {
        precision = precision * 10 + (format[index] - '0');
        index++;
    }

    /* Use precision value to format output */
    return print_with_precision(precision, args);
}

/**
 * print_with_precision - Print formatted output with precision.
 * @precision: Precision value.
 * @args
*/
