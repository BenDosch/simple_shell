#include "includes.h"

/**
 *sigintHandler - makes it so shell does not end on ^C
 *@sig_num: signal reference
 *Return: void no return
 */

void sigintHandler(int sig_num)
{
	signal(SIGINT, sigintHandler);
	write(1, "\nSherlock$ ", 11);
}

int main(int ac, char **av, char **env)
{
	int fb = 0, status;
	ssize_t bufsize = 1024;
	char *buffer, **commands;
	pid_t child;
	struct stat st;

	signal(SIGINT, sigintHandler);
	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		printf("Error, could not allocate memory for buffer\n");
		exit(1);
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "Sherlock$ ", 10);
		fb = getline(&buffer, &bufsize, stdin);
		if (fb == EOF)
		{
			write(1, "logout\n", 7);
			free(buffer);
			exit (0);
		}
		commands = sherlock(buffer, " ");
		if (stat(commands[0], &st) != 0)
			printf("%s: command not found\n", commands[0]);
		else
		{
			child = fork();
			if (child == -1)
			{
				printf("Child ran away\n");
				return (1);
			}
			else if (child == 0)
				execve(commands[0], commands, NULL);
			else
				wait(&status);
		}
	}
	free(buffer);
/* Need to make a free sherlock function */
	return (0);
}
