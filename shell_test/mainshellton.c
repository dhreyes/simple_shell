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
	/*
	int i;
*/
	signal(SIGINT, sighandler);

	while(1)
	{
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, prompt, 10);
		
		input = command();
		/*printf("This is the input: %s\n", input); */
		alltokens = tokenize(input);
		/*
		for (i = 0; alltokens[i]; i++)
		{
			printf("Tokens: <%s>\n", alltokens[i]);
		}
		*/
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
	printf("Caught signal %d coming out\n", signum);
	exit(1);
}
