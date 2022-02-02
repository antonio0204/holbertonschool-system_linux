#include "stdio.h"


size_t _strlen(const char *str)
{
	size_t i;

	while(str[i])
		i++;

	return(i);
}

void main()
{
	const char *h = "HOLBERTON";

	printf("len: %li\n", _strlen(h));
}
