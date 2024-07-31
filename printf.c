#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: Format string.
 * @...: Variable arguments.
 * Return: Number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    unsigned int i = 0, count = 0;
    va_list args;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
        {
            i++;
            count += handle_specifier(format, &i, args);
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);
    return count;
}
