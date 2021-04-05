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
		printf("%s\n", environ[i++]);
	}
	return (0);
}
