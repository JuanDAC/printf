#include "holberton.h"
/**
 * print_number - prints an integer
 * @buffer:receives whole
 * @n:receives int
 * Return: 0
 */
void print_number(char *buffer, int long n)
{
	unsigned int length = 10;
	unsigned int number = n;

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
			n *= 100;
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
/**
 * integer_handler - function handling integer
 * @list_variables: receive list
 * @attribute_length: receive quantity
 * @GC: garbage collection
 * Return:pointer chart
 */
char *integer_handler(
	const garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
)
{
	va_list attributes;
	char *format;
	char *buffer;

	int long current_number;

	(void)GC;

	va_start(attributes, attribute_length);

	buffer = _calloc(RAW_SIZE, sizeof(char));
	/* buffer = malloc(1024 * sizeof(char)); */
	if (buffer == NULL)
		return (NULL);

	if (attribute_length == 1)
	{
		current_number = (int long)va_arg(list_variables, int);
		print_number(buffer, current_number);
	}
	else /* if (attribute_length == 2) */
	{
		format = va_arg(attributes, char *);
		/* add handler format */
		(void)format;
		current_number = (int)va_arg(list_variables, int);
		print_number(buffer, (current_number));
	}

	va_end(attributes);
	return (buffer);
}
/**
 * character_handler - function handling integer
 * @list_variables: receive list
 * @attribute_length: receive quantity
 * @GC: garbage collection
 * Return:pointer chart
 */
char *character_handler(
	const garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
)
{
	va_list attributes;
	char *format;
	char *buffer;

	(void)GC;

	buffer = malloc(sizeof(char) * 2);

	va_start(attributes, attribute_length);

	*(buffer) = (char)va_arg(list_variables, int);
	if (attribute_length > 1)
	{
		format = va_arg(attributes, char *);
		(void)format;
	}
	*(buffer + 1) = '\0';

	return (buffer);
}
/**
 * string_handler - function handling integer
 * @list_variables: receive list
 * @attribute_length: receive quantity
 * @GC: garbage collection
 * Return:pointer chart
 */
char *string_handler(
	const garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
)
{
	va_list attributes;
	char *format;
	char *buffer;

	(void)GC;


	/* buffer = _calloc(RAW_SIZE, sizeof(char)); */

	va_start(attributes, attribute_length);

	buffer = (char *)va_arg(list_variables, char *);
	if (attribute_length > 1)
	{
		format = va_arg(attributes, char *);
		(void)format;
	}

	return (buffer);
}
/**
 * percentage_escape - function handling integer
 * @list_variables: receive list
 * @attribute_length: receive quantity
 * @GC: garbage collection
 * Return:pointer chart
 */
char *percentage_escape_handler(
	const garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
)
{
	char *buffer;

	(void)GC;
	(void)list_variables;
	(void)attribute_length;

	buffer = _calloc(2, sizeof(char));
	*buffer = '%';

	return (buffer);
}






















