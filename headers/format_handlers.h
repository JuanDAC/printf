#ifndef FORMAT_HANDLERS_H
#define FORMAT_HANDLERS_H

char *integer_handler(void *number);
char *character(void *character);
char *string(void *string);
char *generic_integer(void *number);
char *ocatal_integer(void *number);
char *hexadecimal_integer(void *number);
char *unsigned_integer(void *number);
char *short_integer(void *number);

#endif /* FORMAT_HANDLERS_H */
