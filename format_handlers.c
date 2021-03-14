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

char *integer_handler(void *number)
{
	char (*buffer)[1024];

	print_number(buffer, *number);
	return (buffer);
}
char *character(void *character)
{
	return (character);
}
char *string(void *string)
{
	return (string);
}
char *generic_integer(void *number)
{
	return (number);
}

