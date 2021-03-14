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
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (NULL);

	print_number(buffer, *((int *)number));
	return (buffer);
}
char *character_handler(void *character)
{
	return (character);
}
char *string_handler(void *string)
{
	return (string);
}
char *generic_integer_handler(void *number)
{
	return (number);
}

