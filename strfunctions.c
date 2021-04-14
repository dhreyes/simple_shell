#include "shellton.h"
/**
 *_strcmp - compares 2 strings
 *@s1: string 1
 *@s2: string 2
 *Return: 0 if equal, -1 if less, +1 if more
 */
int _strcmp(char *s1, char *s2)
{
	int i, l1, l2;

	i = 0;
	l1 = 0;
	l2 = 0;
	while (s1[l1] != 0)
	{
		l1++;
	}
	while (s2[l2] != 0)
	{
		l2++;
	}
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (l1 > l2)
	{
		return (s1[l2]);
	}
	else if (l1 < l2)
	{
		return (s2[l1] * -1);
	}
	return (0);
}

/**
 * _strdup - returns pointer to new string duplicate
 * of string str
 * @str: string to duplicate
 * Return: On success, _strdup function returns pointer to duplicated
 * string, returns NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	int len;
	char *dup;

	if (str == NULL)
		return (NULL);
	for (len = 0; str[len] != '\0'; len++)
	{
		;
	}
	dup = malloc((sizeof(char) * (len + 1)));
	if (dup == NULL)
		return (NULL);

	while (len >= 0)
	{
		dup[len] = str[len];
		len--;
	}
	return (dup);
}
/**
 * *_strcat - concatenates
 * @dest: first string waiting for attachment
 * @src: string to be attached
 * Return: Always 0 (Success)
 */
int _strlen(char *str);

char *_strcat(char *dest, char *src)
{
	char *ptr = dest + _strlen(dest);

	while (*src != '\0')
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}
/**
 * _strlen - calc length of string
 * @str: input of string
 * Return: index
 */
int _strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
