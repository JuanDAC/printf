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
	GC = malloc(sizeof(garbage_collector_t));

	buffer = evaluator(GC, parser(GC, lexer(GC, format)), raw_argument_list);

	length_buffer = length_str(buffer, false);
	write(1, buffer, length_buffer);

	return (length_buffer);
}
