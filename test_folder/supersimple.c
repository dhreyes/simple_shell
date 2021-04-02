#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 *
 *
 *
 *
 */
int main(void)
{
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	pid = fork();
	wait(0);

	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		printf("nah brah\n");
	}
	printf("papa\n");
	return (0);
}
