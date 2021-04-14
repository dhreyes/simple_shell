#include "shellton.h"


/**
 * main - initializes shellton
 * @ac: ac
 * @av: av
 * @env: env
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	shelltonprompt();
	return (0);
}

/**
 * shelltonprompt - creates the prompt
 */

void shelltonprompt(void)
{
	char *prompt = "SHELLTON$ ";
	char *input;
	char **alltokens;
	pid_t pid;
	int status;

	signal(SIGINT, sighandler);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, prompt, 10);

		input = command();
		alltokens = tokenize(input);
		get_function(alltokens[0]);
		pid = fork();
		if (pid == 0)
		{
			if (execve(alltokens[0], alltokens, NULL) == -1)
				perror("Error");
		}
		else
		{
			wait(&status);
		}
		free(input);
		free(alltokens);
	}
}
