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
int main(int argc, char *argv[])
{
	int id = fork();
	int n, i;
	if (id == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}

	wait(0);
	for (i = n; i < (n + 5); i++)
	{
		printf("%d ", i);
	}
	if (id != 0)
	{
		printf("\n");
	}
	return (0);
}
