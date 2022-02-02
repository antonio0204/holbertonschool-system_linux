#include "signals.h"

/**
 * current_handler_sigaction - return pointer to signal handler
 * Return: handler pointer
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction oldact;

	if (sigaction(SIGINT, NULL, &oldact) == -1)
		return (NULL);
	return (oldact.sa_handler);
}

