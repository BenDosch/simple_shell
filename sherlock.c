#include <stdio.h>
#include <stdlib.h>

void free_d_ptr(char **ptr);

char **sherlock(char *str, const char *delim)
{
	unsigned int i, j, k, end = 0, word = 0, mark = 0, dnum = 0;
	char **words;
	for (i = 0; str[i]; i++)
	{
		for (j = 0; str[i + j] == delim[j] || delim[j] == '\0'; j++)
		{
			if (delim[j] == '\0')
			{
				dnum++;
				i += j - 1;
				break;
			}
		}
	}
	words = malloc(sizeof(char*) * (dnum + 2));
	words[dnum + 1] = '\0';
	if (words == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		for (j = 0; str[i + j] == delim[j] || delim[j] == '\0' || str[i + 1] == '\0'; j++)
		{
			if (str[i + 1] == '\0')
			{
				end = 1;
				i++;
			}
			if (delim[j] == '\0' || str[i] == '\0')
			{
				words[word] = malloc(sizeof(char) * (i - mark + 1));
				if (words[word] == NULL)
				{
					free_d_ptr(words);
					return (NULL);
				}
				for (k = 0; k <= (i - mark); k++)
				{
					if (k == (i - mark))
						(words[word][k]) = '\0';
					else
						(words[word][k]) = str[mark + k];
				}
				word++;
				mark = i + j;
				i += j - 1;
				break;
			}
		}
		if (end == 1)
			break;
	}
	return (words);
}

void free_d_ptr(char **ptr)
{
	int i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
