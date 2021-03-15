#include "../holberton.h"
#include <stdio.h>

int main(void)
{
	int my_len = 0;
	int other_len = 0;


	my_len = _printf("hello %% %d world%%\n-\n", 10);
	printf("original:\n");
	other_len = printf("hello %% %d world%%\n-\n", 10);
	printf("%d == %d\n", my_len, other_len);

	return (0);
}



