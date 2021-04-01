#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAXLET 1000 /* Max number of letters */
#define MAXCOM 100 /* Max number of commands */
#define clear() printf("\033[H\033[J") /* Clear shell using escape sequences */
/**
 * init_shell - greets user on startup
 * Return: none
 *
 */

void init_shell()
{
    clear();
    printf("\n\n\n\n******************"
        "************************");
    printf("\n\n\n\t****MY SHELL****");
    printf("\n\n\t-USE AT YOUR OWN RISK-");
    printf("\n\n\n\n*******************"
        "***********************");
    char* username = getenv("USER");
    printf("\n\n\nUSER is: @%s", username);
    printf("\n");
    sleep(1);
    clear();
}
/**
 * takeInput - receives input from user
 * @str: inputted string
 * Return: Always 0 (Success), else 1
 */
int takeInput(char *str)
{
	char *buff;

	buff = readline("\n>>> ");
	if (strlen(buff) != 0)
	{
		add_history(buff);
		strcpy(str, buff);
		return (0);
	}
	else
	{
		return (1);
	}
}

/**
 * printDir - prints current working directory
 * Return: none
 *
 */
void printDir()
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("\nDir: %s", cwd);
}

/**
 * execArgs - executes arguments inputted from user
 * Return: none
 */

void execArgs(char **parsed)
{

}
