#include "holberton.h"
/**
 * print_number -
 * @buffer:
 * @n:
 * Return:
 */
void print_number(char *buffer, int n)
{
	int length = 10;
	int number = n;

	if (n < 0)
		number = (-n);

	if (n == 0)
	{
		*buffer = '0';
		buffer++;
	}
	else
	{
		if (n < 0)
		{
			n = (-n);
			*buffer = '-';
			buffer++;
			/* n *= 100; */
		}
		for (; n > 0; n /= 100)
			length *= 10;
		for (n = length; n > 0; n /= 10)
			if (!(n == length && ((number / n) % 10) == 0))
			{
				*buffer = ('0' + (number / n) % 10);
				buffer++;
			}
	}
	buffer = '\0';
}
/**
 * integer_handler -
 * @list_variables:
 * @attribute_length:
 * Return:
 */
char *integer_handler(va_list list_variables, const int attribute_length, ...)
{
	va_list attributes;
	char *format;
	int long number;
	char *buffer;

	va_start(attributes, attribute_length);

	/* buffer = _calloc(1024, sizeof(char)); */
	buffer = malloc(1024 * sizeof(char));
	if (buffer == NULL)
		return (NULL);

	if (attribute_length == 1)
	{
		number = (int long)va_arg(list_variables, int);
		print_number(buffer, number);
	}
	else /* if (attribute_length == 2) */
	{
		format = va_arg(attributes, char *);
		/* add handler format */
		(void)format;
		number = (int)va_arg(list_variables, int);
		print_number(buffer, (number));
	}

	va_end(attributes);
	return (buffer);
}
/**
char *character_handler(const int attribute_length, ...)
{
	return ((char *)&(""));
}
char *string_handler(const int attribute_length, ...)
{
	return ((char *)&(""));
}
char *generic_integer_handler(const int attribute_length, ...)
{
	return ((char *)&(""));
}
*/
