#include "holberton.h"

void string_number_alt(char *buffer, int long n)
{
	unsigned long scale, unit, i = 0;

	if (n < 0)
	{
		n *= -1;
		buffer[i] = '-';
		i++;
	}

	for (scale = get_scale(n); scale >= 10; scale /= 10)
	{
		unit = (n / scale);
		if (unit > 9)
		{
			buffer[i] = '0' + (unit / 10);
			i += 1;
			unit %= 10;
		}
		buffer[i] = '0' + unit;
		i += 1;
		n %= scale;
	}
	buffer[i] = '0' + (n / scale);
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


