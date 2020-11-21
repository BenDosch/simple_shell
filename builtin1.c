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

/* setenv built-in */

/* unsetenv built-in */

/* cd built-in */
