#include "includes.h"

/**
 *sl_exit - shell built in Exit
 *@commands: an array of command arguments
 *@buffer: a buffer for reading in commands, passed
 *here to be freed
 *Return: exit status
 */

int sl_exit(char **commands, char *buffer)
{
	free(buffer);
	if (commands[1])
	{
		free_d_ptr(commands);
		exit(1);
	}
	free_d_ptr(commands);
	exit(0);
}

/* env built-in */
/**
 * sl_env - prints current enviroment
 * @commands:
 * @buffer:
 * Return:
 */
int sl_env(char **commands, char *buffer)
{
	int i, j;
	unsigned int varsize;

	printf("in function\n");
	for (i = 0; __environ[i]; i++)
	{
		if (i > 0)
			write(1, "\n", 1);
		printf("in loop\n");
	       	varsize = strlen(__environ[i]);
		write(1, __environ[i], varsize);
	}
	free(buffer);
	return (1);
}


/* setenv built-in */

/* unsetenv built-in */

/* cd built-in */
