#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/**
 *
 *
 *
 */
int main(void)
{
	pid_t our_pid;

	our_pid = getpid();
	printf("%u\n", our_pid);
	return (0);
}
