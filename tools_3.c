#include "holberton.h"

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *buffer;
	int long i;
	if (nmemb == 0 || size == 0)
		return (NULL);
	buffer = malloc((nmemb * size));
	if (buffer == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i += 1)
		*(buffer + i) = 0;
	return ((void *)buffer);
}

int _pow(int base, int expo)
{
	return ((expo == 0) ? 1 : (base * _pow(base, expo - 1)));
}

int paser_int(char *s)
{
	int number_raw, processed_number;
	if (*s == '\0')
		return (0);
	number_raw = ((int)*s) - 48;
	processed_number = number_raw * _pow(10, length_str(s, false)) / 10;
	return (
		(*s == '-')
		? -1 * paserInt(s + 1)
		: processed_number + paser_int(s + 1)
	);
}
int is_number(char *s)
{
	if (s == '\0')
		return (true);
	return (((*s >= '0' && *s <= '9') || *s == '-') && is_number(s + 1));
}

