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
	char colen = ':';
	const char *delim = &colen;
	char **paths = sherlock(_getenv("PATH"), delim);

	for(i = 0; paths[i]; i++)
	{
		printf("%s\n", paths[i]);

		directory = opendir(paths[i]);
		while((dint = readdir(directory)))
		{
			if (_strcmp(dint->d_name, ".") == 0
			    || _strcmp(dint->d_name, "..") == 0)
			{
				printf("Was . or ..\n");
				continue;
			}
			else if (strcmp(dint->d_name, filename) == 0)
			{
				filename = _strcat(dint->d_name, filename); /*maybe have a temp then change it after checks*/
				if (filename == NULL)
				{
					printf("error could not concatonate\n");
				}
				printf("Filename is now now: %s", filename);
				closedir(directory);
				free_d_ptr(paths);
				return (filename);
			}
		}
		printf("Filename not in directory\n");
		closedir(directory);
	}
	free_d_ptr(paths);
	return (NULL);
}
