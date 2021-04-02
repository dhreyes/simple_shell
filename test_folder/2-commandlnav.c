#include <stdio.h>
#include <string.h>
#include <sys/cdefs.h>
/**
 *
 *
 *
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *token = strtok(argv[1], " "); /*Return first token*/

	while (token != NULL) /*Keep printing tokens*/
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
