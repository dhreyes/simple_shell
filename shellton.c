#include <stdio.h>
/**
 *
 *
 *
 */
char* initialize(void)
{
	int buffer;
	char *userin = NULL;
	size_t len = 0;

	printf("$ ");
	buffer = getline(&userin, &len, stdin);
	return (userin);
}
