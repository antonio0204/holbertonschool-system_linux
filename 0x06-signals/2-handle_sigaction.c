#include "signals.h"

/**
 * signal_handler - Action to take in case signal
 * @signum: Signal number
 */
void signal_handler(int signum)
{
	char msg[] = "Gotcha! [0]\n";

	msg[9] = signum + '0';
	write(1, msg, 12);
}

/**
 * handle_sigaction - handles SIGINT signal
 * Return: 0 on success, or -1 on error
 */
int handle_sigaction(void)
{
	struct sigaction act;

	act.sa_handler = signal_handler;
	return (sigaction(SIGINT, &act, NULL));
}

