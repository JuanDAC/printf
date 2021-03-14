#include "holberton.h"

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
}

char *integer_handler(const int attribute_length, ...)
{
	va_list attributes;
	char *buffer;
	int *number;
	char *format;

	va_start(attributes, attribute_length);

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (NULL);
	if (attribute_length == 1)
	{
		number = va_arg(attributes, int *);
		print_number(buffer, *(number));
	}
	else if (attribute_length == 2)
	{
		number = va_arg(attributes, int *);
		format = va_arg(attributes, char *);
		/* add handler format */
		(void)format;
		print_number(buffer, *(number));
	}

	va_end(attributes);
	return (buffer);
}
/*
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
