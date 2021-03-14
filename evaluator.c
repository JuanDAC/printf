#include "holberton.h"


char *(*handler_selector(token_t *token))(void *value)
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
	return (string_handler);
}


char **evaluator(
	token_t *tokens[],
	void *list_variables[],
	char *buffer_acumulator[]
)
{
	int i, j = 0;

	for (i = 0; tokens[i]->type != null; i++)
	{
		if (tokens[i]->need_variable)
		{
			buffer_acumulator[i] = handler_selector(tokens[i])(
				list_variables[j]
			);
			j++;
		}
		else
		{
			buffer_acumulator[i] = tokens[i]->literal;
		}
	}
	return (buffer_acumulator);
}

