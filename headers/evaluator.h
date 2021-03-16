#ifndef EVALUATOR_H
#define EVALUATOR_H
/**
 * Struct _handler_link - heandler
 * @type: variable type
 * @GC: variable GC
 * @list_vsrisbles: list of variables
 * @attribute_length: variable attribute length
 */
typedef struct _handler_link
{
	token_type type;
	char *(*handler)(
		const garbage_collector_t *GC,
		va_list list_variables,
		const int attribute_length,
		...
	);
} handler_link_t;

char *evaluator(
	const garbage_collector_t *GC,
	token_t *tokens[],
	va_list list_variables
);
/**
 * handler_selector - function
 * @token: variable
 * @GC: variable
 * @list_variables: list variables
 * @attribute_length: attribute
 * Return: 0
 */
char *(*handler_selector(token_t *token))(
	const garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
);

#endif /* EVALUATOR_H */
