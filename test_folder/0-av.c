#include <stdio.h>

int main(__attribute__((unused))int argc, char *argv[])
{
	while (*argv)
	{
	printf("%s ", *argv++);
	}
	return (0);
}
