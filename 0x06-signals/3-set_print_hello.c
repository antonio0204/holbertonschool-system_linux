#include "signals.h"

/* Our functions */
void print_hello(int signum)
{
	(void) signum;
	puts("Hello :)");
}

void set_print_hello(void)
{
	struct sigaction act;

	act.sa_handler = print_hello;
	sigaction(SIGINT, &act, NULL);
}
