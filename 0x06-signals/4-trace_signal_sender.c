#include "signals.h"


/**
 * handler - the signal handler address is passed via
 * act.sa_sigaction
 * @sig: number of the signal
 * @info: A pointer to siginfo_t
 * @ucontext: this is a pointer to ucontext_t
 */
void handler(int sig, siginfo_t *info, void *ucontext)
{
	char msg[] = "SIGQUIT sent by 0\n";
	pid_t pid;

	(void) sig;
	(void) ucontext;
	pid = info->si_pid;
	msg[16] = pid + '0';
	write(1, msg, 18);
}

/**
 * trace_signal_sender - shows the pid of the process which sent SIGQUIT
 * Return: 0 on success, or -1 on error
 */
int trace_signal_sender(void)
{
	struct sigaction act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;

	return (sigaction(SIGQUIT, &act, NULL));
}

