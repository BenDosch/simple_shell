#include "includes.h"

/**
 *_strcmp - compares two strings
 *@s1: first string
 *@s2: second string
 *Return: the first difference of strings
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * *dircat - Concatenates dir + / + file and retuns a pointer to its location
 * in memory.
 * @dir: directory that contains file
 * @file: name of file
 * Return: pointer to new string on sucess, NULL on fail.
 */

char *dircat(char *dir, char *file)
{
	size_t i, j;
	char *temp;

	temp = malloc(sizeof(char) * (_strlen(dir) + _strlen(file) + 2));
	if (temp == NULL)
		return (NULL);
	for (i = 0; dir[i] != '\0'; i++)
	{
		temp[i] = dir[i];
	}
	temp[i] = '/';
	i++;
	for (j = 0; file[j] != '\0'; j++)
	{
		temp[i + j] = file[j];
	}
	temp[i + j] = '\0';
	return (temp);
}

/**
 * _strlen - retuns the length of a string without the null char
 * @str: string
 * Return: length of string
 */

size_t _strlen(char *str)
{
	size_t i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}
