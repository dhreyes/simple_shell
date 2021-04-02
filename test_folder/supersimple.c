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
	int idx = 1;
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	pid = fork();
	wait(0);

	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		printf("nah brah\n");
	}
	do {
	pid = fork();
	wait (0);
	idx++;
	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		printf("Nah nah nah");
	}
	}while (pid != 0 && idx < 5);
	printf("papa\n");
	return (0);
}
