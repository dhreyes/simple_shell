#include <stdio.h>
/**
 *
 *
 *
 */
int main(void)
{
	int buffer;
	char *userin = NULL;
	size_t len = 0;

	printf("$ ");
	buffer = getline(&userin, &len, stdin);
	printf("%s", userin);
	return (buffer);
}
