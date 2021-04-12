#include "shellton.h"

char **tokenize(char *input);

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

	char *prompt = "SHELLTON$ ";
	char *input;
	char **tokens;
	pid_t pid;

	write(1, prompt, 10);

	while(1)
	{
		input = command();
		printf("This is the input: %s\n", input);
		tokens = tokenize(input);
		for (
		printf("These are the tokens: %s\n",);
		pid = fork();
		wait (0);
		if (pid == 0)
		{
			execve(input, tokens, NULL);
		}
		free(input);
		write(1, prompt, 10);
		/*
		free(tokens);
*/
	}


	return(0);
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
char **tokenize(char *input)
{
	char *userinput;
	char *token;
	char **alltokens;
	int i = 0;

	alltokens = malloc(sizeof(char *) * (i + 1));
	token = strtok(input, " ");
	alltokens[0] = token;
	while (token != NULL)
	{
		while (alltokens[i] != 0)
		{
		token = strtok(NULL, " ");
		alltokens[i] = token;
		i++;
		}
	}

	alltokens[i] = NULL;
	return (alltokens);
}

void printDir()
{
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
}
