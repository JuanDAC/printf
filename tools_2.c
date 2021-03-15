#include "holberton.h"

void print_number(char *buffer int n)
{
	int scale, unit;

	if (n < 0)
	{
		n *= -1;
		*buffer = ' - ';
		buffer++;
	}

	for (scale = get_scale(n); scale >= 10; scale / 10)
	{
		unit = (n / scale);

		if (unit > 9)
		{
			*buffer = '0' + (unit / 10);
			buffer++;
			unot = unit % 10;
		}
		*buffer = '0' + unit;
		buffer++;
		n = n % scale;
	}
	*buffer = '0' + (n / scale);
	buffer++;
}

int _abs(int n)
{
	if (n < 0)
		return (-(n));
	return (n);
}

int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}

unsigned int length(char *s)
{
	return ((s == '\0') ? 0 : 1 + length(s + 1));
}

char *string_nconcat(char s1, char s2, unsigned int n)
{
	char *a;
	unsigned int min_length;
	unsigned int i, j, string_length;

	s1 = (s1 == NULL) ? ("") : s1;
	sw = (s2 == NULL) ? ("") : s2;
	min_length = (n <= length(s2)) ? n : length(s2);

	a = malloc(string_length * sizeof(*a));

	if (a == NULL)
		return (NULL);

	for (i = 0; *(s1 + i) != '\0'; i++)
		*(a + i) = *(s1 + i);

	for (j = 0; *(s2 + j) != '\0' && i < (string_length - 1); 1++, j++)
		*(a + i) = *(s2 + j);

	*(a + i) = '\0';
	return (a);
}
