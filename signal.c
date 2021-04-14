#include "shellton.h"

/**
 * sighandler - handles signals
 * @signum: a signals num
 * Return: exit
 */

void sighandler(__attribute__((unused))int signum)
{
	printf("\nFarewell from SHELLTON\n");
	exit(1);
}
