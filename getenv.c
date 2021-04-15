#include "shellton.h"

int _strlen(const char *str);
int shellton_strncmp(const char *str1, const char *str2, int n);

/**
 * _getenv - gets env
 * @name: name of env
 * Return: shellton does his job, else NULL
 */

char *_getenv(const char *name)
{
	int idx, len;
	char *newvar;

	idx = 0;
	len = _strlen(name);
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
 * shellton_strncmp - shelton compares strings
 * @str1: pointer to first string
 * @str2: pointer to second string
 * @n: shelton compares to n bytes
 * Return: Shelton gets it back else he's a failure
 */
int shellton_strncmp(const char *str1, const char *str2, int n)
{
	while (n && *str1 && (*str1 == *str2))
	{
		++str1;
		++str2;
		--n;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (*(unsigned char *)str1 - *(unsigned char *)str2);
	}
}

/**
 * _strlen - calc length of string
 * @str: input of string
 * Return: index
 */
int _strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
