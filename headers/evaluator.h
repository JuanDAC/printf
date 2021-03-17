#ifndef EVALUATOR_H
#define EVALUATOR_H
/**
 * struct _handler_link - heandler
 * @type: variable type
 * @handler: var
 */
typedef struct _handler_link
{
	token_type type;
	char *(*handler)(
		garbage_collector_t *GC,
		va_list list_variables,
		const int attribute_length,
		...
	);
} handler_link_t;

char *evaluator(
	garbage_collector_t *GC,
	token_t *tokens[],
	va_list list_variables
);
/**
 * handler_selector - function
 * @GC: variable
 * @list_variables: list variables
 * @attribute_length: attribute
 * Return: 0
 */
char *(*handler_selector(token_t *token))(
	garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
);

#endif /* EVALUATOR_H */
