#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 *
 *
 *
 */
int main(void)
{
	extern char **environ;
	char *arg = "hello";

	int i = 0;
	while(environ[i])
	{
		i++;
	}
	environ[i] = arg;
	if (environ[i] == arg)
	{
		environ[i] = NULL;
	}
	i = 0;
	while(environ[i])
	{
		printf("%s\n", environ[i++]);
	}
	return (0);
}
