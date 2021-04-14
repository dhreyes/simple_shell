#include "shellton.h"

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
	char **alltokens;
	pid_t pid;
	int status;

	signal(SIGINT, sighandler);

	while(1)
	{
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, prompt, 10);
		
		input = command();
		alltokens = tokenize(input);
		
		int i = 0;
		char *path;
		char *pathtoken;
		char **directories;
		int pidx = 0;
		char *pathedtoken;

		while (environ[i] != NULL)
		{
			if (strcmp(environ[i], "PATH") == 0)
				path = environ[i];
			i++;
		}

		pathtoken = strtok(path, ":");

		while (pathtoken != NULL)
		{
			directories[pidx] = strdup(pathtoken); /* Might have to strdup for sake of mem */
			pathtoken = strtok(NULL, ":");
			pidx++;
		}

		char *cwd = getcwd(NULL, 0);
		struct stat sb;

		while (directories[pidx] != NULL)
		{
			chdir(directories[pidx]);
			if (stat(alltokens[0], &sb) == 0)
			{
				alltokens[0] = strcat(directories[pidx], alltokens[0]);
				break;
			}
			pidx++;
		}
		chdir(cwd);

		pid = fork();

		if (pid == 0)
		{
			if (execve(alltokens[0], alltokens, NULL) == -1)
				perror("Error");
		}
		else
		{
			wait (&status);
		}
		free(input);
		free(alltokens);
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

	if (chk == EOF)
	{
		perror("Error");
		free(userin);
		exit(0);
	}
	return (userin);
}
char **tokenize(char *input)
{
	char *token;
	char **alltokens;
	char *input_cp = strdup(input);
	int count = 0;
	char *delim = " \n\t";
	int idx = 0;

	token = strtok(input_cp, delim);
	
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(input_cp);
	alltokens = malloc(sizeof(char *) * (count + 1));

	token = strtok(input, delim);
	while (token != NULL)
	{
		alltokens[idx] = token;
		token = strtok(NULL, delim);
		idx++;
	}
	alltokens[idx] = NULL;
	return (alltokens);
}

void printDir()
{
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
}

void sighandler(int signum)
{
	printf("\nShellton says, \"Goodbye from room #%d\"\n", signum);
	exit(1);
}

int shelltonexit(void);

int shelltonexit()
{
	return (0);
}


