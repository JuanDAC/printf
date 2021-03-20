#include "holberton.h"
/**
 * _strspn - function
 * @s: variable
 * @accept: variable
 * Return: acumulator
 */
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
/**
 * _strlen_recursion - function that makes a recursion
 * @s: variable
 * Return: 0
 */
int _strlen_recursion(char *s)
{
	if (*s != '\0')
	{
		return (1 + _strlen_recursion(s + 1));
	}
	return (0);
}
/**
 * long_int_to_hexa - hexa
 * @GC: ene
 * @n: ene
 * @buffer: to  covert to binary
 * Return: hexa in string
 */
char *long_int_to_hexa(
	garbage_collector_t *GC,
	char *buffer,
	long int n
)
{
	char *a = NULL;
	long int i = 0, j = 0, k = 0, base = 16;
	long int f = n;

	while (f > 0)
	{
		f /= base;
		++i;
	}
	a = GC->malloc(GC, sizeof(char) * (i + 1));
	if (!a)
	{
		return (NULL);
	}
	i = 0, k = 0, f = n;
	while (f > 0)
	{
		a[i] = f % base + 48;
		if (f % base > 9)
			a[i] = f % base + 48 + 39;
		f /= base;
		++i;
	}
	for (j = i - 1; j >= 0; j--, k++)
	{
		buffer[k] = a[j];
	}
	buffer[k] = '\0';
	return (buffer);
}
/**
 * long_int_to_binary - print_binary
 * @GC: to  covert to binary
 * @n: to  covert to binary
 * @buffer: to  covert to binary
 * Return: char
 */
void long_int_to_binary(
	garbage_collector_t *GC,
	char *buffer,
	long int n
)
{
	char *a;
	long int i = 0, j, k, base = 2;
	long int f = n;

	while (f > 0)
	{
		f /= base;
		i++;
	}
	if (f == 0)
	{
		*buffer = '0';
		*(buffer + 1) = '\0';
		return;
	}
	a = GC->malloc(GC, sizeof(char) * (i + 1));
	if (a == NULL)
		return;

	i = 0, k = 0, f = n;
	while (f > 0)
	{
		a[i] = f % base + 48;
		f /= base;
		i++;
	}

	for (j = i - 1; j >= 0; j--, k++)
		buffer[k] = a[j];

	buffer[k] = '\0';
}
