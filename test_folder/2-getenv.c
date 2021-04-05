#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *
 *
 *
 */
char *_getenv(const char *name)
{
	int idx, len;
	extern char **environ;
	char *newvar;

	idx = 0;
	len = strlen(name);
	while (environ[idx])
	{
		if (strncmp(name, environ[idx], len) == 0)
		{
			newvar = environ[idx];
			return (&newvar[len + 1]);
		}
		idx++;
	}

	return (NULL);
}
