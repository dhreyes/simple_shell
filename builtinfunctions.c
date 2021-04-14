#include "shellton.h"
/**
 * get_function - gets a function pointer for shellton
 * @builtin: builtin str being passed
 * Return: func pointer or NULL
 */
int shellton_exit(char *builtin);
int shellton_env(char *builtin);


int (*get_function(char *builtin))(char *str)
{
	my_builtins functions[] = {
		{ "exit\n", shellton_exit },
		{ "env\n", shellton_env },
		{ NULL, NULL }
	};
	int idx = 0;

	while (functions[idx].name)
	{
		if (strcmp(functions[idx].name, builtin) == 0)
			return (functions[idx].func);
		idx++;
	}
	return (NULL);
}
/**
 * shellton_exit - exits shellton
 * @builtin: builtin str being passed
 * Return: none
 */
int shellton_exit(__attribute__((unused))char *builtin)
{
	exit(0);
}
/**
 * shellton_env - gets the env for shellton
 * @builtin: builtin str being passed
 * Return: Always 0 (Success)
 */
int shellton_env(__attribute__((unused))char *builtin)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
