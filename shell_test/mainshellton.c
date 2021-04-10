#include "shellton.h"

char *tokenize(char *input);

/**
 * main - initializes shellton
 *
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	shelltonprompt();

	return(0);
}

void shelltonprompt()
{
	char *prompt = "SHELLTON$ ";
	char *input;
	char *tokens;

	write(1, prompt, 10);

	while(1)
	{
		input = command();
		tokens = tokenize(input);

		free(input);
	}
}

char *command(void)
{
	char *userin;
	size_t buffer = 256;
	int chk;

	userin = malloc(sizeof(char) * buffer);

	if (userin == NULL)
	{
		free(userin);
		return(0);
	}

	chk = getline(&userin, &buffer, stdin);

	if (chk == -1)
	{
		perror("Error: ");
		return (0);
	}
	return (userin);
}
char *tokenize(char *input)
{
	char *userinput;
	char *token;

	token = strtok(input, " ");

	while (token != NULL)
	{
		token = strtok(NULL, " ");
	}
	return (token);
}
