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
<<<<<<< HEAD
	int i = 0;

=======
	char *exit = "exit";
	/*
	int i;
*/
>>>>>>> 4fdad02645569f1bc0f6d4461ee89ef86b69aed3
	signal(SIGINT, sighandler);

	while(1)
	{
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, prompt, 10);
		
		input = command();
<<<<<<< HEAD
		if (strcmp(input,"exit\n") == 0)
		{
			free(input);
			exit(0);
		}
		if (strcmp(input,"env\n") == 0)
		{
			while(environ[i] != NULL)
			{
				printf("%s\n", environ[i]);
				i++;
			}
		}
	/*printf("This is the input: %s\n", input); */
		if (!(strcmp(input,"env\n") == 0))
		{
			alltokens = tokenize(input);
		}
=======
		
		/*printf("This is the input: %s\n", input); */
		alltokens = tokenize(input);
>>>>>>> 4fdad02645569f1bc0f6d4461ee89ef86b69aed3
		/*
		for (i = 0; alltokens[i]; i++)
		{
			printf("Tokens: <%s>\n", alltokens[i]);
		}
		*/
		
	/*	if (strcmp(alltokens, exit) == 0)
			return (0);
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
<<<<<<< HEAD
	printf("\nCaught signal %d coming out\n", signum);
=======
	printf("\nShellton says, \"Goodbye from room #%d\"\n", signum);
>>>>>>> 4fdad02645569f1bc0f6d4461ee89ef86b69aed3
	exit(1);
}

int shelltonexit(void);

int shelltonexit()
{
	return (0);
}

/* PATH */

int i = 0;

while (environ[i] != NULL)
{
	if (strcmp(environ[i], "PATH") == 0)
		return (environ[i]);
	i++;
}

char *path;
char *pathtok;
char **directories




