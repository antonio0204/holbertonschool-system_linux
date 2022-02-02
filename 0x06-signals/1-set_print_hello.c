#include "signals.h"

/* Our functions */
void print_hello(int signum)
{
	(void) signum;
	puts("Hello :)");
}

void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
