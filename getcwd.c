#include "shellton.h"
/**
 *
 *
 *
 */
void printDir()
{
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
}
