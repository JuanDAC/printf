#include "holberton.h"
/**
 * _printf -
 * @format:
 * Return:
 */

int _printf(const char *format, ...)
{
	garbage_collector_t *GC;
	int attribute_length = 0, length_buffer = 0, i;
	token_t **tokens;
	char **raw_buffer, buffer[RAW_SIZE];
	va_list raw_argument_list;

	va_start(raw_argument_list, format);
	GC = malloc(sizeof(garbage_collector_t));
	raw_buffer = malloc(sizeof(char *) * RAW_SIZE);

	(void)buffer;

	tokens = lexer(GC, format, &attribute_length);
	tokens = parser(GC, tokens);
	/* get attribute length  */
	for (i = 0, attribute_length = 0; tokens[i]; i++)
		if (tokens[i]->type != normal_string && tokens[i]->type != percentage_escape)
			attribute_length++;

	raw_buffer = evaluator(GC, tokens, raw_argument_list, raw_buffer);
	for (i = 0; raw_buffer[i] ; i++)
		write(1, raw_buffer[i], length_str(raw_buffer[i], false));

	/* write(1, buffer, length_buffer); */

	return (length_buffer);
}
