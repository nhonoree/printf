#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Function prototypes */
int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *s);
int print_percent(void);
int print_int(int n);
int print_binary(unsigned int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n);
int print_hex_upper(unsigned int n);
int print_pointer(void *p);
int print_string_custom(char *s);
int print_reversed(char *s);
int print_rot13(char *s);

#endif /* MAIN_H */
