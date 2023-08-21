#include "main.h"
#include <stdio.h>

/**
 * _printf - prints output according to format
 * @format: string being passed
 * Return: char to be printed
 */
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
				{
					case 'c':
						count += printf(" %c ", va_arg(args, int));
						break;
					case 's':
						count += printf(" %s ", va_arg(args, char *));
						break;
					case '%':
						count += printf(" %% ");
						break;
					default:
						break;
				}
				i++;
		}
		else
		{
			count += printf(" %c ", format[i]);
		}
	}
	va_end(args);
	return (count);
}
