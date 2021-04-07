#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/cdefs.h>

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

char *_getenv(const char *name);
list_t *print_path();

#endif
