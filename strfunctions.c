#include "shellton.h"
/**
 *_strcmp - compares 2 strings
 *@s1: string 1
 *@s2: string 2
 *Return: 0 if equal, -1 if less, +1 if more
 */
int _strcmp(const char *s1, const char *s2)
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
 * str_concat - Concatenate (combine) two strings
 * @s1: First string
 * @s2: Second string
 * Return: Pointer to new space in memory, NULL if it fails
 */
char *str_concat(char *s1, char *s2)
{
	char *s3, *empt;
	int i, len1, len2, j;

	empt = "";
	if (s1 == NULL)
		s1 = empt;
	if (s2 == NULL)
		s2 = empt;
	i = len1 = len2 = 0;
	while (s1[len1] != '\0')
	{
		len1++;
	}
	while (s2[len2] != '\0')
	{
		len2++;
	}
	len2++;
	s3 = malloc((len1 + len2) * sizeof(char *));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}
