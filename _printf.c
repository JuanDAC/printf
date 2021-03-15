#include "holberton.h"
#include <stdio.h>

int _printf(const char *format, ...)
{
	garbage_collector_t *GC;
	int attribute_length = 0, i, j;
	token_t **tokens;
	char *raw_buffer[1024];
	char buffer[1024];
	va_list raw_argument_list;
	void **list_variables;
	int length_buffer = 0;

	GC = malloc(sizeof(garbage_collector_t));

	(void)format;
	(void)buffer;
	(void)list_variables;
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
		if (tokens[i]->type != without_adding)
		{
			write(1, tokens[i]->literal, length_str(tokens[i]->literal, false));
		}
		else
		{
			write(1, "-", 1);
		}
	}
#endif /* DEV */


	 /* get  */
	list_variables = malloc(sizeof(void *) * (attribute_length + 1))
	va_start(raw_argument_list, format);
	for (i = 0, j = 0; tokens[i]; i++)
	{
		if (tokens[i].normal_string )
	}



	//evaluator(GCt garbage_collector_t *GC, tokens, lst_variablesist_variables, raw_buffer);
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

