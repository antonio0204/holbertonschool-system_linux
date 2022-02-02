#include "signals.h"


/**
 * main - program to print info
 * @argc: argument count
 * @argv: Argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	printf("%d: %s\n", atoi(argv[1]), strsignal(atoi(argv[1])));
	return (EXIT_SUCCESS);
}

