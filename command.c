#include "shellton.h"

/**
 * command - recieves command
 * Return: user input
 */

char *command(void)
{
	char *userin;
	size_t buffer = 256;
	int chk;

	userin = malloc(sizeof(char) * buffer);

	if (userin == NULL)
	{
		free(userin);
		return (0);
	}
	chk = getline(&userin, &buffer, stdin);
	if (chk == EOF)
	{
		perror("Error");
		free(userin);
		exit(0);
	}
	return (userin);
}
