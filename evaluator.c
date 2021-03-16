#include "holberton.h"

char *(*handler_selector(token_t *token))(va_list list_variables, const int attribute_length, ...)
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


char **evaluator(
	const garbage_collector_t *GC,
	token_t *tokens[],
	va_list list_variables,
	char **buffer_acumulator
)
{
	int i;

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
	return (buffer_acumulator);
}

