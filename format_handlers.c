#include "holberton.h"

/**
 * integer_handler - function handling integer
 * @list_variables: receive list
 * @attribute_length: receive quantity
 * @GC: garbage collection
 * Return:pointer chart
 */
char *integer_handler(
	garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
)
{
	va_list attributes;
	char *format;
	char *buffer;

	long int current_number;

	va_start(attributes, attribute_length);

	buffer = GC->malloc(GC, BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);

	if (attribute_length == 1)
	{
		current_number = (long int)va_arg(list_variables, int);
		long_int_to_string(buffer, current_number);
	}
	else/* if (attribute_length == 2) */
	{
		format = va_arg(attributes, char *);
		/* add handler format */
		(void)format;
		current_number = (int)va_arg(list_variables, int);
		long_int_to_string(buffer, (current_number));
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
	garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
)
{
	va_list attributes;
	char *format;
	char *buffer;

	(void)GC;

	buffer = GC->malloc(GC, sizeof(char) * 2);

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
	garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
)
{
	va_list attributes;
	char *format;
	char *buffer;
	int i;

	(void)GC;


	va_start(attributes, attribute_length);

	buffer = (char *)va_arg(list_variables, char *);
	if (buffer == NULL)
	{
		buffer = GC->malloc(GC, sizeof(char) * STR_NULL_LON);
		for (i = 0; i < STR_NULL_LON; i++)
			buffer[i] = STR_NULL[i];
	}
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
	garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
)
{
	char *buffer;

	(void)GC;
	(void)list_variables;
	(void)attribute_length;

	buffer = GC->malloc(GC, 2 * sizeof(char));
	*buffer = '%';
	*(buffer + 1) = '\0';

	return (buffer);
}


