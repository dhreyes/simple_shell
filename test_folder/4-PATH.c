#include "header.h"

void _print_path()
{
	char *path;
	char *token;

	path = getenv("PATH");
	token = strtok(path, ":");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
}

/*
1. a. create a list (hardcode node 0)
b. create a function to create node 0

check project singly linked list
*/



list_t *add_node(list_t **head, const char *str)
{
	list_t *nnode = malloc(sizeof(list_t));
	int idx = 0;

	if (nnode == NULL)
		return (NULL);

	if (str == NULL)
	{
		nnode->str = NULL;
		nnode->len = 0;
	}
	else
	{
		nnode->str = strdup(str);
		while (str[idx])
		{
			idx++;
		}
		nnode->len = idx;
	}
	nnode->next = *head;
	*head = nnode;
	return (nnode);
}
