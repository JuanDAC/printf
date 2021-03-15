#include "holberton.h"

token_t *create_token(
	const garbage_collector_t *GC,
	token_type type, char *literal,
	handler_function_t type_handler
)
{
	token_t *new_token;

	(void)GC;
	new_token = malloc(sizeof(token_t));
	if (new_token == NULL)
		return (NULL);

	new_token->literal = literal;
	new_token->type_handler = type_handler;
	new_token->type = type;

	return (new_token);
}


token_t *raw_lexical_analyzer(const garbage_collector_t *GC, char *character)
{
	token_t *current_token;
	(void)GC;

	if (*(character) == '%')
		current_token = create_token(
			GC,
			formated,
			character,
			equal_handler
		);
	/* else if (*character == '%' && (*(character + 1) == '%' || *(character + 1) == ' ')) */
	/* current_token = create_token(GC, normal_percentage, character, equal_handler); */
	else
		current_token = create_token(GC, normal_string, character, equal_handler);

	if (current_token == NULL)
		return (NULL);

	return (current_token);
}

token_t **lexer(
	const garbage_collector_t *GC,
	const char *format,
	int *attribute_length
)
{
	int i;
	char *current_format;
	token_t **raw_tokens;

	raw_tokens = malloc(1024 * sizeof(token_t));
	if (raw_tokens == NULL)
		return (NULL);
	current_format = (char *)format;

	for (i = 0; format[i] != '\0'; i++)
	{
		raw_tokens[i] = raw_lexical_analyzer(GC, current_format + i);
		if (raw_tokens[i]->type == format_specification)
			*(attribute_length) += 1;
	}
	raw_tokens[i] = NULL;


	return (raw_tokens);

}

