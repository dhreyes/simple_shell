#include <stdio.h>
#include <unistd.h>
/**
 *
 *
 *
 */
int main(void)
{
	extern char **environ;

	int i = 0;
	while(environ[i])
	{
		i++;
	}
	environ[i] = "hello";
	environ[i + 1] = NULL;
	i = 0;
	while(environ[i])
	{
		printf("%s\n", environ[i++]);
	}
	return (0);
}
