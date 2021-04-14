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
	int (*temp)(char *str);
	char *exit = "exit\n";
	char *env = "env\n";

	signal(SIGINT, sighandler);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, prompt, 10);

		input = command();
		if (strcmp(input, exit) == 0)
		{
			temp = get_function(input);
			if (temp != NULL)
			{
				free(input);
				temp("exit");
			}
		}
		if (strcmp(input, env) == 0)
		{
			temp = get_function(input);
			if (temp != NULL)
			{
				temp("env");
			}
			free(input);
			continue;
		}
		alltokens = tokenize(input);
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
