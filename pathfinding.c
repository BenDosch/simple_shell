#include "includes.h"

/**
 * get_file_path - get directory from PATH if it contains a file
 * @filename: filename to check for full path
 * Return: path that contains the named file, on fail returns NULL
 */

char *get_file_path(char *filename)
{
	DIR *directory;
	struct dirent *dint;
	int i, status;
	char **paths = sherlock(_getenv("PATH"));
	char *path;

	for(i = 0; paths[i], i++)
	{
		directory = open(paths[i]);
		while(dint = readdir(directory))
		{
			if (_strcmp(dint->d_name, '.') == 0 || _strcmp(dint->d_name, '..') == 0)
				continue;
			else if (_strcmp(dint->d_name, filename) == 0)
			{
				path = _strcpy(dint->d_name) /* make a _strcpy */
				if (path == NULL)
				{
					/* error */
				}
				close(directory);
				free_d_ptr(paths)
				return (path);
			}
		}
		close(directory);
	}
	free_d_ptr(paths);
	return (NULL);
}
