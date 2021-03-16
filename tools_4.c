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
 * return_hexa - hexa
 * @n: ene
 * Return: hexa in string
 */
char *return_hexa(int n)
{
	char *a = NULL, *copy_a = NULL;
	int i = 0, j = 0, k = 0, base = 16;
	int f = n;

	while (f > 0)
	{
		f /= base;
		++i;
	}
	a = malloc(sizeof(char) * (i + 1));
	copy_a = malloc(sizeof(char) * (i + 1));
	if (!copy_a || !a)
	{
		free(a);
		free(copy_a);
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
		copy_a[k] = a[j];
	}
	copy_a[k] = '\0';
	return (copy_a);
}
/**
 * return_binary - print_binary
 * @n: to  covert to binary
 * Return: char
 */
char *return_binary(int n)
{
	char *a, *copy_a;
	int i = 0, j, k, base = 2;
	int f = n;

	while (f > 0)
	{
		f /= base;
		++i;
	}
	if (f == 0)
	{
		copy_a = "0";
		return (copy_a);
	}
	a = malloc(sizeof(char) * (i + 1));
	copy_a = malloc(sizeof(char) * (i + 1));
	if (!copy_a || !a)
	{
		free(a);
		free(copy_a);
		return (NULL);
	}
	i = 0, k = 0, f = n;
	while (f > 0)
	{
		a[i] = f % base + 48;
		f /= base;
		++i;
	}
	for (j = i - 1; j >= 0; j--, k++)
	{
		copy_a[k] = a[j];
	}
	copy_a[k] = '\0';
	return (copy_a);
}
