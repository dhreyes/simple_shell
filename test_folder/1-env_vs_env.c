#include <stdio.h>

int main(int ac, char **av, char **env)
{
	extern char **environ;
	
	printf("%p\n", &environ);
	printf("--\n");
	printf("%p\n", &env);
}
