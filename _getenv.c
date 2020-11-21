#include "includes.h"

/**
 * _getenv - gets the environmental vairable's value
 * @name: Name of environmental varialble to access
 * Return: pointer to environmental variable value
 */


char *_getenv(const char *name)
{
	int i, j;

	for (i = 0; __environ[i]; i++)
	{
		for (j = 0; 1; j++)
		{
			if (name[j] == '\0' && __environ[i][j] == '=')
				return (&(__environ[i][j + 1]));
			else if (name[j] == __environ[i][j])
				continue;
			else
				break;
		}
	}
	return (NULL);
}
