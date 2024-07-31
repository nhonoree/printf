#include "main.h"

/**
 * handle_specifier - Handles format specifiers.
 * @format: Format string.
 * @index: Pointer to the current index in the format string.
 * @args: Argument list.
 * Return: Number of characters printed for this specifier.
 */
int handle_specifier(const char *format, unsigned int *index, va_list args)
{
    int count = 0;

    switch (format[*index])
    {
        case 'c':  /* Handle character specifier */
            _putchar(va_arg(args, int));
            count = 1;
            break;

        case 's':  /* Handle string specifier */
            {
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    _putchar(*str++);
                    count++;
                }
            }
            break;

        case '%':  /* Handle percent specifier */
            _putchar('%');
            count = 1;
            break;

        default:
            /* If the specifier is not recognized, return 0 or handle as an error */
            break;
    }

    return count;
}
