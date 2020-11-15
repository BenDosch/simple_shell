#include "includes.h"

/* exit built-in */
int sl_exit(char **commands, char *buffer)
{
	free(buffer);
	if (commands[1])
		exit(1);
	exit(0);
}
/* env built-in */

/* setenv built-in */

/* unsetenv built-in */

/* cd built-in */
