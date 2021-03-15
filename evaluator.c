#include "holberton.h"


char *(*handler_selector(token_t *token))(const int attribute_length, ...)
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
	void *list_variables[],
	char *buffer_acumulator[]
)
{
	int i, j = 0;

	(void)GC;
	for (i = 0; tokens[i]->type != null; i++)
	{
		switch(tokens[i]->type_handler)
		{
			case equal_handler:
				buffer_acumulator[i] = tokens[i]->literal;
				break;
			case simple_handler:
				buffer_acumulator[i] = handler_selector(tokens[i])(
					1,
					list_variables[j]
				);
				j++;
				break;
			case complex_handler:
				buffer_acumulator[i] = handler_selector(tokens[i])(
					2,
					list_variables[j],
					tokens[i]->literal
				);
				j++;
				break;
		}
	}
	return (buffer_acumulator);
}

