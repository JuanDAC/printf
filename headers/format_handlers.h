#ifndef FORMAT_HANDLERS_H
#define FORMAT_HANDLERS_H

char *integer_handler(
	const garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
);
char *character_handler(
	const garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
);
char *string_handler(
	const garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
);
char *percentage_escape_handler(
	const garbage_collector_t *GC,
	va_list list_variables,
	const int attribute_length,
	...
);
#endif /* FORMAT_HANDLERS_H */
