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
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}

	return (0);
}
