#include "includes.h"

int main(void)
{
	int fb = 0, status;
	char *buffer;
	size_t bufsize = 1024;
	pid_t child;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		printf("Error, could not allocate memory for buffer\n");
		exit(1);
	}
	printf("$ ");

	while (fb != 1)
	{

		getline(&buffer, &bufsize, stdin);
		char commands[] = sherlock(buffer, " ");
		child = fork();
		if (child == -1)
		{
			printf("Child ran away\n");
			return (1);
		}
		else if (child == 0)
		{
			execve(commands[0], commands, NULL);
			sleep(3);
		}
		else
		{
			wait(&status);
			printf("$ ");
		}
	}
	return (0);
}
