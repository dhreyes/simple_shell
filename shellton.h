#ifndef SHELLTON_H
#define SHELLTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

extern char **environ;

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

typedef struct aliases
{
	char *alias_name; /* compare to user command */
	char *real_name; /* returns this if they match */
} alias;

typedef struct my_builtins
{
	char *name;
	int (*func)(char *builtin);
} my_builtins;

void shelltonprompt();
char *command();
char **tokenize(char *input);
void printDir();
void sighandler(int signum);
int (*get_function(char *builtin))(char *str);
char *getpath(char **s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);

#endif
