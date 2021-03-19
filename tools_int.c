#include "holberton.h"

/**
 * reverse - function
 * @buffer: buffer
 * @string_len: variable
 * Return: 0
 */
bool reverse(char *buffer, size_t string_len)
{
	size_t i, j;
	char swap;

	for (i = 0, j = string_len - 1; i < j; i++, j--)
	{
		swap = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = swap;
	}
	return (true);
}
/**
 * unsigned_long_int_to_string - function
 * @buffer: buffer
 * @n: variable
 * Return: i
 */
size_t unsigned_long_int_to_string(char *buffer, unsigned long int n)
{
	size_t i = 0;

	do {
		buffer[i++] = n % 10 + '0';
	} while (n /= 10);
	buffer[i] = '\0';

	reverse(buffer, i);
	return (i);
}
/**
 * long_int_to_string - function
 * @buffer: buffer
 * @n: variable
 * Return: i
 */
size_t long_int_to_string(char *buffer, long int n)
{
	size_t i = 0;
	long int sign_selector;
	unsigned long int number_scale;

	sign_selector = (n >> ((sizeof(long int) * 8) - 1));
	number_scale = (n + sign_selector) ^ sign_selector;

	do {
		buffer[i++] = number_scale % 10 + '0';
	} while (number_scale /= 10);

	buffer[i] = '-';
	i += sign_selector & 1;
	buffer[i] = '\0';

	reverse(buffer, i);
	return (i);
}
