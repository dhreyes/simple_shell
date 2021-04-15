#include "shellton.h"

int shellton_strncmp(const char *str1, const char *str2, unsigned int n);

/**
 * _getenv - will get environ variable
 * @name: var name to be passed
 * Return: env var or NULL
 */
char *_getenv(const char *name)
{
	int idx, len, i;
	char *newvar;

	idx = i = len = 0;
	while (name[i])
	{
		i++;
		len++;
	}
	while (environ[idx])
	{
		if (shellton_strncmp(name, environ[idx], len) == 0)
		{
			newvar = environ[idx];
			return (&newvar[len + 1]);
		}
		idx++;
	}

	return (NULL);
}

/**
 * shellton_strncmp - shellton compares two strings
 * @str1: string 1 to be compared
 * @str2: string 2 to be compared
 * @n: compare to nth bytes
 * Return: shllton was a good boy, else -1
 */
int shellton_strncmp(const char *str1, const char *str2, unsigned int n)
{
	(void)n;

	while (*str1 == *str2)
	{
		if (*str1 == '\0' || *str2 == '\0')
			break;
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0')
		return (0);
	else
		return (-1);
}
