#ifndef TOOLS_H
#define TOOLS_H

bool reverse(char *buffer, size_t string_len);
size_t unsigned_long_int_to_string(
	char *buffer,
	unsigned long int n
);
size_t long_int_to_string(
	char *buffer,
	long int n
);
char *long_int_to_hexa(
	garbage_collector_t *GC,
	char *buffer,
	long int n
);
void long_int_to_binary(
	garbage_collector_t *GC,
	char *buffer,
	long int n
);

char *_strcat(char *dest, char *src);
char *rot13(char *n);
char *str_concat(garbage_collector_t *GC, char *s1, char *s2);
int get_scale(int n);
int _abs(int n);
int _isalpha(int c);
void *_calloc(unsigned int nmemb, unsigned int size);
int _pow(int base, int expo);
int paserInt(char *s);
int is_number(char *s);
unsigned int _strspn(char *s, char *accept);
int _strlen_recursion(char *s);
unsigned int length_str(char *string, bool count_null);
int includes(char *s, char c);
char *string_nconcat(garbage_collector_t *GC, char *s1,
	char *s2, unsigned int n);
char *str_copy(garbage_collector_t *GC,
	char *from_string, unsigned int length);
char *_strdup(garbage_collector_t *GC, char *str);
void string_number_alt(char *buffer, int long n);
#endif /* TOOLS_H */
