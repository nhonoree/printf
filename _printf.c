#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function.
 * @format: Format string.
 * @...: Arguments.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    count += print_char(va_arg(args, int));
                    break;
                case 's':
                    count += print_string(va_arg(args, char *));
                    break;
                case '%':
                    count += print_percent();
                    break;
                case 'd':
                case 'i':
                    count += print_int(va_arg(args, int));
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
                    count += print_hex(va_arg(args, unsigned int));
                    break;
                case 'X':
                    count += print_hex_upper(va_arg(args, unsigned int));
                    break;
                case 'p':
                    count += print_pointer(va_arg(args, void *));
                    break;
                case 'S':
                    count += print_string_custom(va_arg(args, char *));
                    break;
                case 'r':
                    count += print_reversed(va_arg(args, char *));
                    break;
                case 'R':
                    count += print_rot13(va_arg(args, char *));
                    break;
                default:
                    write(1, "%", 1);
                    count++;
                    if (*format)
                        write(1, format, 1);
                    count++;
                    break;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);
    return (count);
}
