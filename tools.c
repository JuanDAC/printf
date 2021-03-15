#include "holberton.h"


unsigned int length_str(char *string, bool count_null)
{
	return (
		(*string == '\0')
		? (unsigned int)count_null
		: 1 +  length_str(string + 1, count_null)
	);
}


int includes(char *s, char c)
{
	if (*s == '\0')
		return (false);
	return ((*s == c) || includes(s + 1, c));
}


char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *string;
	unsigned int min_length;
	unsigned int i, j, string_length;

	s1 = (s1 == NULL) ? ("") : s1;
	s2 = (s2 == NULL) ? ("") : s2;
	min_length = (n <= length_str(s2, false)) ? n : length_str(s2, false);
	string_length = length_str(s1, false) + min_length + 1;
	string = malloc(string_length * sizeof(*string));

	if (string == NULL)
		return (NULL);

	for (i = 0; *(s1 + i) != '\0'; i++)
		*(string + i) = *(s1 + i);

	for (j = 0; *(s2 + j) != '\0' && i < (string_length - 1); i++, j++)
		*(string + i) = *(s2 + j);


	*(string + i) = '\0';

	return (string);
}

char *str_copy(char *from_string, unsigned int length)
{
	unsigned int i;
	char *new_string;

	new_string = malloc((length + 1) * sizeof(*from_string));
	if (new_string == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		new_string[i] = from_string[i];
	new_string[i] = '\0';

	return (new_string);

}


char *_strdup(char *str)
{
	char *new_str;
	unsigned int i, longitud;

	if (str == NULL)
		return (NULL);
	longitud = length(str);
	new_str = (char *)malloc(sizeof(cha) * longitud);

	if (new_str == NULL || longitud == o)
		return (NULL);
	for (i = 0; i != longitud; i++)
		*(new_str + i) = *(str + i);

	return (new_str);
}
