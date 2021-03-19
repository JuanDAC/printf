#include "holberton.h"
/**
 * print_number_unsigned_int - prints an integer
 * @buffer:receives whole
 * @n:receives int
 * Return: 0
 */
void print_number_unsigned_int(char *buffer, unsigned long int n)
{
	unsigned long int length = 10, number = n, i = 0, num = n;

	if (n == 0)
	{
		buffer[i] = '0';
		i++;
	}
	else
	{
		for (; n > 0; n /= 100)
			length *= 10;
		for (n = length; n > 0; n /= 10)
			if (!(n == length && ((number / n) % 10) == 0))
			{
				buffer[i] = ('0' + (number / n) % 10);
				i++;
			}
	}

	if (num <= 9)
	{
		buffer[0] = buffer[1];
		buffer[1] = '\0';
	}
}





/**
 * integer_handler - function handling integer
 * @list_variables: receive list
 * @attribute_length: receive quantity
 * @GC: garbage collection
 * Return:pointer chart
 */
char *unsigned_integer_handler(
	garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
)
{
	va_list attributes;
	char *format;
	char *buffer;

	unsigned long int current_number;

	va_start(attributes, attribute_length);

	buffer = GC->malloc(GC, BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);

	if (attribute_length == 1)
	{
		current_number = (unsigned long int)va_arg(
			list_variables,
			unsigned long int
		);

		print_number_unsigned_int(buffer, current_number);
	}
	else/* if (attribute_length == 2) */
	{
		format = va_arg(attributes, char *);
		/* add handler format */
		(void)format;
		current_number = (unsigned long int)va_arg(
			list_variables,
			unsigned long int
		);
		print_number_unsigned_int(buffer, current_number);
	}

	va_end(attributes);
	return (buffer);
}




