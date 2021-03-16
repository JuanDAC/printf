#include "holberton.h"
/**
 * print_rev - ptint backwards
 * @buffer: buffer
 * @s: variable printing variable
 * Return: void
 */
void print_rev(char *buffer, char *s)
{
	int i;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	i--;
	while (i >= 0)
	{
		s--;
		i--;
		*buffer = *s;
		buffer++;
	}
	*buffer = '\n';
	buffer++;
}
/**
 * _strcat - check the code
 * @dest: this is variable 1
 * @src: this is variable 2
 * Return: always 0
 */
char *_strcat(char *dest, char *src)
{
	int count1, count2;

	for (count1 = 0; dest[count1] != '\0'; count1++)
	{}
	for (count2 = 0; src[count2] != '\0'; count2++)
	{
		dest[count1 + count2] = src[count2];
	}
	return (dest);
}
/**
 * rot13 - check the code
 * @n: the variable
 * Retuern: n
 */
char *rot13(char *n)
{
	char alp[] = "ABCDEFGHIJKLMNOPQRSTVWXYZabcdefghijklmnopqrstvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstvwxyzabcdefghijklm";
	int i, j;

	for (i = 0; n[i] != '\0'; i++)
		for (j = 0; alp[j] != '\0'; j++)
			if (n[i] == alp[j])
			{
				n[i] = rot[j];
				break;
			}
	return (n);
}
/**
 * str_concat - 
 * @s1:
 * @s2:
 * Return:
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int i, j, length_s1 = 0, length_s2 = 0;
	char *k;

	if (s1 == NULL)
		s1 = ("");

	if (s2 == NULL)
		s2 = ("");

	length_s1 = length_str(s1, false);
	length_s2 = length_str(s2, false);
	k = malloc(sizeof(char) * (length_s1 + length_s2 - 1));

	if (k == NULL)
		return (NULL);

	for (i = 0; *(s1 + i) != '\0'; i++)
		*(k + i) = *(s1 + i);

	for (j = 0; *(s2 + j) != '\0'; i++, j++)
		*(k + i) = *(s2 + j);

	return (k);
}
/**
 * get_scale -
 * @n:
 * Return:
 */
int get_scale(int n)
{
	if (n > 10)
		return (10 * get_scale(n / 10));
	else
		return (1);
}
