#include <stdio.h>

int main(__attribute__((unused))int argc, char *argv[])
{
	argv++;
	while (*argv)
	{
	printf("%s\n", *argv++);
	}
	return (0);
}
