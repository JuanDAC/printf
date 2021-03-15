#include "holberton.h"

void print_number_alternative(char *buffer, int n)
{
	int scale, unit;

	if (n < 0)
	{
		n *= -1;
		*buffer = '-';
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


