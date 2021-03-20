#include "holberton.h"

/**
 * unsigned_integer_handler - function handling integer
 * @GC: garbage collection
 * @list_variables: receive list
 * @attribute_length: receive quantity
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
			unsigned int
		);

		unsigned_long_int_to_string(buffer, current_number);
	}
	else/* if (attribute_length == 2) */
	{
		format = va_arg(attributes, char *);
		/* add handler format */
		(void)format;
		current_number = (unsigned long int)va_arg(
			list_variables,
			unsigned int
		);
		unsigned_long_int_to_string(buffer, current_number);
	}

	va_end(attributes);
	return (buffer);
}


/**
 * binary_integer_handler - function handling integer
 * @list_variables: receive list
 * @attribute_length: receive quantity
 * @GC: garbage collection
 * Return: pointer chart
 */

char *binary_integer_handler(
	garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...)
{
	va_list attributes;
	char *format;
	char *buffer;

	long int current_number;

	buffer = GC->malloc(GC, BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);

	if (attribute_length == 1)
	{
		current_number = (long int)va_arg(
			list_variables,
			int
		);
		long_int_to_binary(GC, buffer, current_number);
	}
	else
	{
		format = va_arg(attributes, char *);
		(void)format;
		current_number = (unsigned long int)va_arg(
			list_variables,
			unsigned int
		);
		long_int_to_binary(GC, buffer, current_number);
	}

	va_end(attributes);
	return (buffer);
}
