#ifndef EVALUATOR_H
#define EVALUATOR_H

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

char *(*handler_selector(token_t *token))(
	const garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
);

#endif /* EVALUATOR_H */
