#include "signals.h"

/**
 * signal_handler - Action to take in case signal
 * @signum: Signal number
 * Return: 0 on Success, or -1 on Error
 */
void signal_handler(int signum)
{
	char msg[] = "Gotcha! [0]\n";

	msg[9] = signum + '0';
	write(1, msg, 12);
}

/**
 * handle_signal - handles SIGINT signal
 * Return: 0 on success, or -1 on error
 */
int handle_signal(void)
{
	if (signal(SIGINT, signal_handler) == SIG_ERR)
		return (-1);
	return (0);
}

