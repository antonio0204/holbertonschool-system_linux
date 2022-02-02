#include <sys/types.h>
#include <signal.h>

/**
 * pid_exist - a function that tests if a process exists, given its PID
 * @pid: PID to check if it exists
 * Return: 1 if the process with the PID pid exists, or 0 otherwise
 */
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) + 1);
}
