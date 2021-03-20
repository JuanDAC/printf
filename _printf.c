#include "holberton.h"
/**
 * _printf - function to do formatted printing
 * @format: text formating
 * Return: number caracter printer or -1 if format is NULL or %
 */

int _printf(const char *format, ...)
{
	garbage_collector_t *GC;
	int length_buffer;
	char *buffer;
	va_list raw_argument_list;

	if (NULL_OR_ONLY_PERCENTAGE(format))
		return (-1);

	va_start(raw_argument_list, format);
	GC = create_garbage_collector();

	if (HANDLER_EXCEED_BUFFER(format))
		buffer = (char *)(format);
	else
		buffer = evaluator(GC, parser(GC, lexer(GC, format)), raw_argument_list);

	if (buffer == NULL)
		return (-1);

	length_buffer = length_str(buffer, false) ? length_str(buffer, false) : 1;
	write(1, buffer, length_buffer);

	va_end(raw_argument_list);
	GC->free_all(GC);
	free(GC->subscriptions);
	free(GC);
	return (length_buffer);
}

