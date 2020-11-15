#include "includes.h"


int main(void)
{
	char *buff;
	size_t buffsize = 1024;
	char **files;
	struct stat st;
	int i;

	buff = malloc(sizeof(char) * buffsize);
	getline(&buff, &buffsize, stdin);

	files = sherlock(buff, " ");


	for(i = 0; files[i]; i++)
	{
		if (stat(files[i], &st) == 0)
			printf(" FOUND\n");
		else
			printf(" NOT FOUND\n");
	}
	return (0);
}
