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
	int i;
	char **paths = sherlock(_getenv("PATH"));

	for(i = 0; paths[i], i++)
	{
		directory = open(paths[i]);
		while(dint = readdir(directory))
		{
			if (_strcmp(dint->d_name, '.') == 0 || _strcmp(dint->d_name, '..') == 0)
				continue;
			else if (_strcmp(dint->d_name, filename) == 0)
			{
				filename = _strcat(dint->dname, filename); /*maybe have a temp then change it after checks*/
				if (filename == NULL)
				{
					/* error could not concatonate*/
				}
				close(directory);
				free_d_ptr(paths)
				return (filename);
			}
		}
		close(directory);
	}
	free_d_ptr(paths);
	return (NULL);
}
