#include "includes.h"


char *_getenv(const char *name)
{
	int i, j;

	for (i = 0; __environ[i]; i++)
	{
		for (j = 0; 1; j++)
		{
			if (name[j] == '\0' && __environ[i][j] == '=')
				return (&(__environ[i][j + 1]));
			else if(name[j] == __environ[i][j])
				continue;
			else
				break;
		}
	}
}

int main(int ac, char **av, char **env)
{
	printf("Pointer %p\n", _getenv(av[1]));
	printf("Value: %s\n", _getenv(av[1]));
}
