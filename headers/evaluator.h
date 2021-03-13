#ifndef EVALUATOR_H
#define EVALUATOR_H

void evaluator(token_t *tokens[], void *list_variables[]);
char* (*handler_selector(token_t *token))(void *value);

#endif /* EVALUATOR_H */
