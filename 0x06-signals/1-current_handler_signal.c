#include "signals.h"

/**
 * current_handler_signal - returns the pointer to curent signal handler
 * Return: pointer to function
 */
void (*current_handler_signal(void))(int)
{
	void (*handler)(int);

	handler = signal(SIGINT, SIG_DFL);

	if (handler == SIG_ERR || signal(SIGINT, handler) == SIG_ERR)
		return (NULL);

	return (handler);
}

