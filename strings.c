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
 * *dircat - Concatenates dir + / + file and changes the pointer of file to
 * the new location in memory after freeing what file pointed to.
 * @dir: directory that contains file
 * @file: name of file
 * Return: 1 on sucess, 0 on fail.
 */

char *dircat(char *dir, char *file)
{
	size_t i, j;
	char *temp;

	temp = malloc(sizeof(char) * (_strlen(dir) +_strlen(file) + 2));
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
	printf("filename: %s\n", file);
	printf("dirname: %s\n", dir);
	printf("temp: %s\n", temp);
	file = temp;
	printf("file now: %s\n", file);
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
	return(i);
}
