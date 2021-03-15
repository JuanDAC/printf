#include "holberton.h"
#include <stdio.h>


int _printf(const char *format, ...)
{
	garbage_collector_t *GC;
	int attribute_length = 0, length_buffer = 0, i, j;
	token_t **tokens;
	char *raw_buffer[1024], buffer[1024];
	va_list raw_argument_list;

	va_start(raw_argument_list, format);
	GC = malloc(sizeof(garbage_collector_t));

	(void)format;
	(void)buffer;
	(void)raw_buffer;

	tokens = lexer(GC, format, &attribute_length);
#ifdef DEV
	write(1, "lexer:\n", 7);
	for (i = 0; tokens[i]; i++)
	{
		if (tokens[i]->type != formated)
		{
			write(1, tokens[i]->literal, 1);
		}
		else
		{
			write(1, "-", 1);
		}
	}
#endif /* DEV */
	tokens = parser(GC, tokens);
#ifdef DEV
	write(1, "parser:\n", 8);
	for (i = 0; tokens[i]; i++)
	{
		write(1, tokens[i]->literal, length_str(tokens[i]->literal, false));
	}
#endif /* DEV */


	 /* get attribute length  */

	for (i = 0, attribute_length = 0; tokens[i]; i++)
		if (tokens[i]->type != normal_string && tokens[i]->type != percentage_escape)
			attribute_length++;
/*
	for (i = 0, j = 0; tokens[i]; i++)
	{
		if (tokens[i]->type != normal_string && tokens[i]->type != percentage_escape)
		{
			printf("get len %d\n", attribute_length);
			printf("get arg %d\n", ((double *)list_variables[j]));
			j++;
		}
	}
	list_variables[j] = NULL;
	va_end(raw_argument_list);
	*/

	write(1, "evaluator:\n", 11);
	evaluator(GC, tokens, raw_argument_list, raw_buffer);
	write(1, "fin evaluator:\n", 15);
	for (i = 0, j = 0; tokens[i]; i++)
	{
	/*	if (tokens[i]->type != remove_string)
		{*/
			buffer[j] = *tokens[i]->literal ? *tokens[i]->literal : '-';
			j++;
		/*}*/
	}
	buffer[j] = '\0';
	length_buffer = length_str(buffer, false);

#ifdef DEV
	printf("length_buffer -> %d\n", length_buffer);
	printf("attribute_length -> %d\n", attribute_length);
	write(1, "final:\n", 7);
#endif /* DEV */
	write(1, buffer, length_buffer);

	return (length_buffer);
}

