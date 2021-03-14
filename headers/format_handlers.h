#ifndef FORMAT_HANDLERS_H
#define FORMAT_HANDLERS_H

char *integer_handler(void *number);
char *character_handler(void *character);
char *string_handler(void *string);
char *generic_integer_handler(void *number);
char *ocatal_integer_handler(void *number);
char *hexadecimal_integer_handler(void *number);
char *unsigned_integer_handler(void *number);
char *short_integer_handler(void *number);

#endif /* FORMAT_HANDLERS_H */
