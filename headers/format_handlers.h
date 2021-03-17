#ifndef FORMAT_HANDLERS_H
#define FORMAT_HANDLERS_H

char *integer_handler(
	garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
);
char *character_handler(
	garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
);
char *string_handler(
	garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
);
char *percentage_escape_handler(
	garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
);
#endif /* FORMAT_HANDLERS_H */
