#include "holberton.h"
/**
 * length_str - Walk the size of a string
 * @string: Receive an address
 * @count_null: Receive an address
 * Return: return to string
 */
unsigned int length_str(char *string, bool count_null)
{
	return (
		(*string == '\0')
		? (unsigned int)count_null
		: 1 +  length_str(string + 1, count_null)
	);
}

/**
 * includes - enters a pointer
 * @s: char
 * @c: char
 * Return: always 0 succes
 */
int includes(char *s, char c)
{
	if (*s == '\0')
		return (false);
	return ((*s == c) || includes(s + 1, c));
}

/**
 * string_nconcat - enters a pointer
 * @GC: Receive a character
 * @s1: Receive a character
 * @s2: Receive a character
 * @n: Receive a unsigned
 * Return: always 0 secces
 */
char *string_nconcat(garbage_collector_t *GC, char *s1,
	char *s2, unsigned int n)
{
	char *n_concat_string;
	unsigned int min_length;
	unsigned int i, j, string_length;

	s1 = (s1 == NULL) ? ("") : s1;
	s2 = (s2 == NULL) ? ("") : s2;
	min_length = (n <= length_str(s2, false)) ? n : length_str(s2, false);
	string_length = length_str(s1, false) + min_length + 1;
	n_concat_string = GC->malloc(GC, string_length * sizeof(*n_concat_string));

	if (n_concat_string == NULL)
		return (NULL);

	for (i = 0; *(s1 + i) != '\0'; i++)
		*(n_concat_string + i) = *(s1 + i);

	for (j = 0; *(s2 + j) != '\0' && i < (string_length - 1); i++, j++)
		*(n_concat_string + i) = *(s2 + j);


	*(n_concat_string + i) = '\0';

	return (n_concat_string);
}

/**
 * str_copy - Copy a string
 * @GC: garbage collector
 * @from_string: char
 * @length: unsigned
 * Return: new_string
 */
char *str_copy(garbage_collector_t *GC, char *from_string, unsigned int length)
{
	unsigned int i;
	char *new_string;

	new_string = GC->malloc(GC, (length + 1) * sizeof(*from_string));
	if (new_string == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		new_string[i] = from_string[i];
	new_string[i] = '\0';

	return (new_string);
}

/**
 * _strdup - Dynamic memory copy
 * @GC: Character address
 * @str: Character address
 * Return: new_str
 */
char *_strdup(garbage_collector_t *GC, char *str)
{
	char *new_str;
	unsigned int i, longitud;

	if (str == NULL)
		return (NULL);
	longitud = length_str(str, true);
	new_str = (char *)GC->malloc(GC, sizeof(char) * longitud);

	if (new_str == NULL || longitud == 0)
		return (NULL);
	for (i = 0; i != longitud; i++)
		*(new_str + i) = *(str + i);

	return (new_str);
}
