#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len2 = printf("Let's print a simple sentence.\n");
	write(1, "hm\%", 4);
	return (0);
}
