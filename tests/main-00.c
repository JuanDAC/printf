#include "../holberton.h"
#include <stdio.h>

int main(void)
{
	int my_len = 0;
	int other_len = 0;
	

	my_len =_printf("hello %%%% world%%\n-\n");
	printf("original:\n");
	other_len = printf("hello %%%% world%%\n-\n");
	printf("%d == %d\n", my_len, other_len);

	return (0);
}



