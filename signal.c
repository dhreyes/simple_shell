#include "shellton.h"

/**
 * sighandler - handles signals
 * @signum: a signals num
 * Return: Shellton says Farewell!
 */

void sighandler(__attribute__((unused))int signum)
{
	exit(1);
}
