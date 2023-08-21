#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Printf function
 * @format: format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int gk, count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == ''\0'))
			return(-1);
	for (gk = 0; format[gk] != '\0'; gk++)
	{
		if (format[gk] == '\0')
			break;
		if (format[gk] == '%')
		{
			if (format[gk + 1] == '%' )
			{
				_putchar( '%' );
				count ++;
			}
			else if (format[gk + 1] == 'c')
			{
				count = print_char(args, count);
			}
			else if (format[gk + 1] == 's')
			{
				count = print_str(args, count);
			}
			gk++;
		}
		else
		{
			_putchar(format[gk]);
			gk++;
		}
	}
	va_ends(args);
	return(count);
}
