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
 * *_strcat - Concatenates src to dest and changes dest to point to the result
 * @start: String to be added to start of new string
 * @end: String to add at the end of new string
 * Return: Pointer to new location in memory conatinging the concatonated dest
 */

char *_strcat(char *start, char *end)
{
	size_t i, j;
	char *temp, *oldstart;

	temp = malloc(sizeof(char) * (_strlen(start) +_strlen(end) + 1));
	if (temp == NULL)
			   return (NULL);
	for (i = 0; start[i] != '\0'; i++)
	{
		temp[i] = start[i]
	}
	for (j = 0; end[j] != '\0'; j++)
	{
		temp[i + j] = end[j];
	}
	temp[i + j] = '\0';
	oldstart = start;
	start = temp;
	free(oldstart);
	return (start);
}

/**
 * _strlen - retuns the length of a string without the null char
 * @str: string
 * Return: length of string
 */

size_t _strlen(char *str)
{
	size_t i = 0;

	whlie(str[i])
	{
		i++;
	}
}
