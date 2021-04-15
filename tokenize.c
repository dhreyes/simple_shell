#include "shellton.h"

/**
 * tokenize - parses input
 * @input: user input
 * Return: alltokens
 */

char **tokenize(char *input)
{
	char *token;
	char **alltokens;
	char *input_cp = _strdup(input);
	int count = 0;
	char *delim = " :\n\t";
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
