#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main ()
{
	printf("PATH : %s\n", _getenv("PATH"));

	return(0);
}
