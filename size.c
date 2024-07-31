#include "main.h"

/**
 * handle_length_modifier - Process length modifiers for conversion specifiers.
 * @format: Format string.
 * @index: Current index in the format string.
 * @args: Argument list.
 * Return: Number of characters printed.
 */
int handle_length_modifier(const char *format, int index, va_list args)
{
    char length_modifier = format[index];
    int count = 0;

    switch (length_modifier)
    {
        case 'l':
            /* Handle long int or long double */
            /* Example: Convert long int */
            count += print_long_int(va_arg(args, long int));
            break;
        case 'h':
            /* Handle short int */
            /* Example: Convert short int */
            count += print_short_int(va_arg(args, int) & 0xFFFF);
            break;
        default:
            /* No length modifier or unsupported modifier */
            break;
    }

    return count;
}

/**
 * print_long_int - Print long integer.
 * @n: The long integer to print.
 * Return: Number of characters printed.
 */
int print_long_int(long int n)
{
    char buffer[22];  /* Long int can be up to 21 digits + sign */
    int len = 0;

    /* Convert long int to string */
    /* Handle conversion */
    
    /* Write the string */
    return write(1, buffer, len);
}

/**
 * print_short_int - Print short integer.
 * @n: The short integer to print.
 * Return: Number of characters printed.
 */
int print_short_int(int n)
{
    char buffer[6];  /* Short int can be up to 5 digits + sign */
    int len = 0;

    /* Convert short int to string */
    /* Handle conversion */
    
    /* Write the string */
    return write(1, buffer, len);
}
