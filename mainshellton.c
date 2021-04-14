#include "shellton.h"

void shelltonprompt(void);
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
	char *prompt = "$ ";
	char *input;
	char **alltokens;
	pid_t pid;
	int status;
	int (*temp)(char *str);
	char *xit = "exit\n";
	char *env = "env\n";
	char *cwd;
	struct stat sb;
	char **directories;
	int pidx;
	char *slash = "/";
	char *path = strdup(getenv("PATH"));
	char *catpath;
	char *fullpath;

	signal(SIGINT, sighandler);
	directories = tokenize(path);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, prompt, 2);

		input = command();

		if (input == NULL)
		{
			free(path);
			free(directories);
			exit(0);
		}

		cwd = getcwd(NULL, 0);

		if (strcmp(input, xit) == 0)
		{
			temp = get_function(input);
			if (temp != NULL)
			{
				free(input);
				free(directories);
				free(path);
				free(cwd);
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

		for (pidx = 0; directories[pidx] != NULL; pidx++)
		{
			chdir(directories[pidx]);
			if (stat(alltokens[0], &sb) == 0)
			{
				catpath = str_concat(directories[pidx], slash);
				fullpath = str_concat(catpath, alltokens[0]);
				free(catpath);
				break;
			}
		}

		chdir(cwd);
		pid = fork();

		if (pid == 0)
		{
			if (execve(fullpath, alltokens, NULL) == -1)
				perror("Error");
		}
		else
		{
			wait(&status);
		}
		free(input);
		free(alltokens);
		free(fullpath);
		free(cwd);
	}
}
