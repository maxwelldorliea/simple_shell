#include <stdarg.h>
#include "shell.h"


/**
 * _putchar - print a char
 * @ch: char
 * Return: int
 */


int _putchar(int ch)
{
	return (write(1, &ch, 1));
}


/**
 * pr_str - prints a string
 * @args: va_list
 * Return: int
 */


int pr_str(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		_putchar(*s);
		len++;
		s++;
	}


	return (len);
}



/**
 * _printf - produces output according to a format
 * @format: char pointer
 * Return: int
 */

int _printf(const char *format, ...)
{
	int i = 0, cnt = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
		{
			cnt += _putchar(format[i]);
			i++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			cnt += _putchar(format[++i]);
			i++;
			continue;
		}
		if (format[++i] == 's')
		{
			cnt += pr_str(args);
		}
		else
		{
			if (format[i] == '\0')
				return (-1);
			cnt += _putchar(format[i - 1]);
			cnt += _putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (cnt);
}
