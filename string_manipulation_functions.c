#include "header.h"

/**
 * _strlen - return string length.
 * @s: string pointer.
 * Return: string length.
 */
int _strlen(char *s)
{
	int i = 0;

	while ((*(s + i) != '\0'))
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp - compare strings
 * @s1: string
 * @s2: string
 * Return: 0 if strings are equal, non-zero, otherwise.
 */
int _strcmp(const char *s1, const char *s2)
{
	int s1len = 0;
	int s2len = 0;
	int len = 0;
	int i;

	s1len = strlen(s1);
	s2len = strlen(s2);

	if (s2len >= s1len)
		len = s1len;
	else
		len = s2len;
	for (i = 0; i < len; i++)
	{
		if (s2[i] != s1[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

/**
 * _const_strconcat - concatenates s2 to the end of s1.
 * @s1: string 1.
 * @s2: string 2.
 * Return: pointer to char of the new concatenated string.
 */
char *_const_strconcat(const char *s1, const char *s2)
{
	int len1 = 0, len2 = 0, lens_sum, i;
	char *str;

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	lens_sum = len1 + len2;
	str = malloc(sizeof(char) * (lens_sum + 1));

	if (str == NULL)
		return (NULL);

	for (i = 0; i < lens_sum; i++)
	{
		if (i < len1)
			str[i] = s1[i];
		else
			str[i] = s2[i - len1];
	}
	str[lens_sum] = '\0';
	return (str);
}

/**
 * _strconcat - concatenates s2 to s1.
 * @s1: string 1.
 * @s2: string 2.
 * Return: pointer to character of the new concatenated string.
 */
char *_strconcat(char *s1, char *s2)
{
	int len1 = 0, len2 = 0, lens_sum, i;
	char *str;

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	lens_sum = len1 + len2;
	str = malloc(sizeof(char) * (lens_sum + 1));
	/* str = malloc(sizeof(char) * 1000); */

	if (str == NULL)
		return (NULL);

	for (i = 0; i < lens_sum; i++)
	{
		if (i < len1)
			str[i] = s1[i];
		else
			str[i] = s2[i - len1];
	}
	str[lens_sum] = '\0';
	return (str);
}

/**
 * _strdup - returns a pointer to newly allocated memory space, which contains
 * a copy of the string given as a parameter.
 * @str: string
 * Return: str or NULL.
 */
char *_strdup(char *str)
{
	int len = 0;
	char *p;
	int i;

	if (str == '\0')
		return (NULL);
	while (str[len] != '\0')
		len++;
	p = malloc(sizeof(char) * len + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= len; i++)
		p[i] = str[i];
	return (p);
}
