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
/**
 * struct my_builtins - builtin struct for builtins
 * @name: string name of builtin
 * @func: function pointer
 */

typedef struct my_builtins
{
	char *name;
	int (*func)(char *builtin);
} my_builtins;

void shelltonprompt(void);
char *command();
char **tokenize(char *input);
void sighandler(int signum);
int (*get_function(char *builtin))(char *str);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
char *_getenv(const char *name);

#endif
