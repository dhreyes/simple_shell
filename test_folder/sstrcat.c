#include <stdio.h>

int main(void)
{
	char *h = "/bin";
	char *w = "ls";
	char *result;

	result = _strcat(h, w);
	printf("%s\n", result);

	return (0);
}
