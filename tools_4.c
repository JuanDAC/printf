#include "holberton.h"

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, acumulator = 0;

	for (i = 0; *(s + i) != '\0'; i++)

		if (includes(accept, *(s + i)))
			acumulator += 1;
		else
			break;
	return (acumulator);
}

int _strlen_recursion(char *s)
{
	if (*s != '\0')
	{
		return (1 + _strlen_recursion(s + 1));
	}
	return (0);
}