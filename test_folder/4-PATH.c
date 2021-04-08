#include "header.h"

size_t print_list(const list_t *h);
list_t *add_node_end(list_t **head, const char *str);
char *_getenv(const char *name);

list_t *print_path()
{
	char *path;
	char *token;
	list_t *head;

	head = malloc(sizeof(list_t));
	path = _getenv("PATH");
	token = strtok(path, ":");
	head->str = strdup(token);

	while (token != NULL)
	{
		token = strtok(NULL, ":");
		add_node_end(&head, token);

	}
	return (head);
}

/**
 * print_list - prints elements of list_t
 * @h: head of list_t
 * Return: amount of nodes
 */
size_t print_list(const list_t *h)
{
	size_t n = 0;

	if (h == NULL)
		return (n);

	while (h != NULL)
	{
		if (h->str != NULL)
			printf("%s\n", h->str);
		h = h->next;
		n++;
	}
	return (n);
}

/*
1. a. create a list (hardcode node 0)
b. create a function to create node 0

check project singly linked list
*/

int main()
{
	list_t *list;
	list = malloc(sizeof(list_t));

	list = print_path();

	print_list(list);
	return (0);
}


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


list_t *add_node_end(list_t **head, const char *str)
{
	list_t *nnode = malloc(sizeof(list_t));
	list_t *cnode = *head;
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
	nnode->next = NULL;
	if (*head == NULL)
		*head = nnode;
	else
	{
		while (cnode->next != NULL)
			cnode = cnode->next;
		cnode->next = nnode;
	}

	return (nnode);
}
