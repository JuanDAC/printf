#ifndef EVALUATOR_H
#define EVALUATOR_H

typedef struct _handler_link
{
	token_type type;
	char *(*handler)(const int attribute_length, ...);
} handler_link_t;

char **evaluator(
	token_t *tokens[],
	void *list_variables[],
	char *buffer_acumulator[]
);

char *(*handler_selector(token_t *token))(const int attribute_length, ...);


#endif /* EVALUATOR_H */
