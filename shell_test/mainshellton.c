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
	pid_t pid;


	while(1)
	{
		write(1, prompt, 10);
		input = command();
		printf("This is the input: %s\n", input);
		tokens = tokenize(input);
		printf("These are the tokens: %s\n", tokens);
		pid = fork();
		wait (0);

		if (pid == 0)
		{
			execve(input, &tokens, NULL);
		}
		free(input);
		/*
		free(tokens);
*/
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
	char *alltokens;

	token = strtok(input, " ");

	while (token != NULL)
	{

		token = strtok(NULL, " ");
	}
	return (token);
}

void printDir()
{
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
}
