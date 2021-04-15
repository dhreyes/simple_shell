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
	chk = getline(&userin, &buffer, stdin);

	if (userin == NULL)
	{
		free(userin);
		return (0);
	}
	if (chk == EOF)
	{
		free(userin);
		return (NULL);
	}
	return (userin);
}
