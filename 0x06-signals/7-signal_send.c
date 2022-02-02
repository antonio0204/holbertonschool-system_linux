#include "signals.h"

/**
 * main - program to send SIGINT to a process
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	pid_t pid;

	if (argc < 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	pid = atoi(argv[1]);

	if (kill(pid, SIGINT) == -1)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

