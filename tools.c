#include "holberton.h"


int length_str(char *string, bool count_null)
{
	return ((*string = '\0') ? (int)count_null : 1 +  length_str(string + 1, count_null));
}









