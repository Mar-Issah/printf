#include "main.h"

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
	{
	int count = 0;
	va_list args;
	int (*function)(va_list) = NULL;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			format++;
			function = get_function(format);
			if (*(format) == '\0')
				return (-1);
			else if (function == NULL)
			{
				_putchar(*(format - 1));
				_putchar(*format);
				count += 2;
			}
			else
				count += function(args);
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			format++;
			_putchar('%');
			count++;
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
