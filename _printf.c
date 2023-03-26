#include "main.h"
#include <stddef.h>

/**
 * _printf - Produces output according to a format
 * @format: Is a character string. The format string
 * is composed of zero or more directives
 *
 * Return: The number of characters printed (excluding
 * the null byte used to end output to strings)
 **/

int _printf(const char *format, ...)
{
	  va_list args;
    va_start(args, format);

    int count = 0;

    while (*format != '\0')
		{
        if (*format == '%')
				{
            format++;
            if (*format == 'c')
						{
                int c = va_arg(args, int);

                _putchar(c);
                count++;
            }
						else if (*format == 's')
						{
                char *s = va_arg(args, char*);
                while (*s != '\0')
								{
                    _putchar(*s);
                    s++;
                    count++;
                }
            }
						else if (*format == '%')
						{
                _putchar('%');
                count++;
            }
        }
				else
				{
            _putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return (count);
}
