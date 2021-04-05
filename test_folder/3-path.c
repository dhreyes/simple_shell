#include "header.h"

void _print_path()
{
	char *path;
	char *token;

	path = getenv("PATH");
	token = strtok(path, ":");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
}
