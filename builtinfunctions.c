#include "shellton.h"
/**
 * remember: free everything before exit!!!!!!
 *
 *
 */
int shellton_exit(char *builtin);
int shellton_env(char *builtin);


int (*get_function(char *builtin))(char *str)
{
	my_builtins functions[] = {
		{ "exit\n", shellton_exit },
		{ "env\n", shellton_env },
		/*
		{ "setenv", setenv },
		{ "unsetenv", unsetenv },
		{ "cd", cd },
		*/
		{ NULL, NULL }
	};
	
	int idx = 0;

	while (functions[idx].name)
	{
		if(strcmp(functions[idx].name, builtin) == 0)
			return (functions[idx].func);
		idx++;
	}
	return (NULL);
}

int shellton_exit(__attribute__((unused))char *builtin)
{
	exit(0);
}

int shellton_env(__attribute__((unused))char *builtin)
{
	int i = 0;

	while(environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
