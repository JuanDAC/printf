#include "holberton.h"
#include <stdio.h>

int _printf(const char *format, ...)
{
	garbage_collector_t *GC;
	int attribute_length = 0, i;
	token_t **tokens;


	GC = malloc(sizeof(garbage_collector_t));

	(void)format;

	tokens = lexer(
		GC,
		format,
		&attribute_length
	);

	for (i = 0; tokens[i]; i++)
	{
		write(1, tokens[i]->literal, 1);
	}
	printf("%d\n", attribute_length);

	return (0);
}

