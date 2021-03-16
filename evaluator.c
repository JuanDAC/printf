#include "holberton.h"

char *(*handler_selector(token_t *token))(va_list list_variables,
	const int attribute_length, ...
)
{
	int i;

	handler_link_t format_handlers_link[] = {
		{integer, integer_handler},
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


char *cure_buffer(char **raw_buffer)
{
	unsigned long i, j, k;
	char *buffer;

	buffer = malloc(sizeof(char) * RAW_SIZE);
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
	const garbage_collector_t *GC,
	token_t *tokens[],
	va_list list_variables
)
{
	int i;
	char **buffer_acumulator;

	buffer_acumulator = malloc(sizeof(char *) * RAW_SIZE);
	if (buffer_acumulator == NULL)
		return (NULL);

	(void)GC;
	for (i = 0; tokens[i]; i++)
	{
		switch (tokens[i]->type_handler)
		{
			case simple_handler:
				buffer_acumulator[i] = handler_selector(tokens[i])(
					list_variables,
					1
				);
				break;
			case complex_handler:
				buffer_acumulator[i] = handler_selector(tokens[i])(
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
	return (cure_buffer(buffer_acumulator));
}

