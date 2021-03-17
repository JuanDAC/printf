#include "holberton.h"
/**
 * handler_selector - selector the function handler
 * @GC: garbage collector
 * @list_variables: current token to sellect handler
 * @attribute_length: current token to sellect handler
 * Return: Alwais a function handler
 */
char *(*handler_selector(token_t *token))(
	garbage_collector_t *GC
	, va_list list_variables,
	const int attribute_length,
	...
)
{
	int i;

	handler_link_t format_handlers_link[] = {
		{integer, integer_handler},
		{character, character_handler},
		{string, string_handler},
		{percentage_escape, percentage_escape_handler},
		{character, character_handler},
		{null, NULL}
	};

	for (i = 0; format_handlers_link[i].type != null; i++)
	{
		if (token->type == format_handlers_link[i].type)
		{
			return (format_handlers_link[i].handler);
		}
	}
	return (integer_handler); /* replace with a function equal*/
}


/**
 * cure_buffer - selector the function handler
 * @GC: garbage collector
 * @raw_buffer: raw buffer extract data
 * Return: cure_buffer ona dimencion or NULL error
 */
char *cure_buffer(garbage_collector_t *GC, char **raw_buffer)
{
	unsigned long i, j, k;
	char *buffer;

	(void)GC;

	buffer = GC->malloc(GC, sizeof(char) * RAW_SIZE);
	if (buffer == NULL)
		return (NULL);

	for (i = 0, j = 0; raw_buffer[i] ; i++)
	{
		if (length_str(raw_buffer[i], false) == 1)
		{
			buffer[j] = *raw_buffer[i];
			j++;
		}
		else
		{
			for (k = 0; k < length_str(raw_buffer[i], false); k++)
				buffer[j + k] = raw_buffer[i][k];
			j += k;
		}
	}
	buffer[j] = '\0';

	return (buffer);
}


char *evaluator(
	garbage_collector_t *GC,
	token_t *tokens[],
	va_list list_variables
)
{
	int i;
	char **buffer_acumulator;

	buffer_acumulator = GC->malloc(GC, sizeof(char *) * RAW_SIZE);
	if (buffer_acumulator == NULL)
		return (NULL);

	(void)GC;
	for (i = 0; tokens[i]; i++)
	{
		switch (tokens[i]->type_handler)
		{
			case simple_handler:
				buffer_acumulator[i] = handler_selector(tokens[i])(
					GC,
					list_variables,
					1
				);
				break;
			case complex_handler:
				buffer_acumulator[i] = handler_selector(tokens[i])(
					GC,
					list_variables,
					2,
					tokens[i]->literal
				);
				break;
			default:/* case equal_handler: */
				buffer_acumulator[i] = tokens[i]->literal;
				break;
		}
	}
	buffer_acumulator[i] = NULL;
	return (cure_buffer(GC, buffer_acumulator));
}

