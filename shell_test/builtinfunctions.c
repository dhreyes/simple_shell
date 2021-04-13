#include "shellton.h"
/**
 * remember: free everything before exit!!!!!!
 *
 *
 */
void shellton_exit(char *builtin);


void get_function(char *builtin)
{
	my_builtins functions[] = {
		{ "exit\n", shellton_exit },
		/*
		{ "env", shellton_env },
		{ "setenv", setenv },
		{ "unsetenv", unsetenv },
		{ "cd", cd },
		*/
		{ NULL, NULL }
	};
	
	int idx = 0;
	int *function;

	while (functions[idx].name)
	{
		if(functions[idx].name == builtin)
			functions[idx].func;
		idx++;
	}
}

void shellton_exit(char *builtin)
{
	exit(0);
}
