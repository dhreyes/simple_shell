#include "shellton.h"
/**
 * remember: free everything before exit!!!!!!
 *
 *
 */
void shellton_exit(char *builtin);


void *get_function(char *builtin)
{
	my_builtins functions[] = {
		{ "exit", shellton_exit },
		/*
		{ "env", shellton_env },
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

void shellton_exit(__attribute__((unused))char *builtin)
{
	exit(0);
}
