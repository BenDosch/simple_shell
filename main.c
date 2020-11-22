#include "includes.h"

/**
 *sigintHandler - makes it so shell does not end on ^C
 *@sig_num: signal reference
 *Return: void no return
 */

void sigintHandler(int sig_num)
{
	(void)sig_num;
	signal(SIGINT, sigintHandler);
	write(1, "\n$ ", 3);
}

/**
 *runexe - runs an executable file
 *@commands: an array of arguments
 *Return: 0 on success
 */

int runexe(char **commands)
{
	pid_t child;
	struct stat st;
	int status;
	char *no_dir = commands[0];

	if (commands[0][0] == '/')
	{
		if (stat(commands[0], &st) != 0)
			write(1, "No such file or directory\n", 26);
	}
	else
	{
		commands[0] = get_file_path(commands[0]);
		if (stat(no_dir, &st) == 0 && commands[0] == NULL)
		{
			free(commands[0]);
			commands[0] = no_dir;
		}
		else
		free(no_dir);
	}
	if (commands[0] == NULL)
		write(1, "No such file or directory\n", 26);
	else
	{       child = fork();
		if (child == -1)
		{       write(1, "Fork Failed\n", 12);
			return (1);             }
		else if (child == 0)
		{
			execve(commands[0], commands, NULL);
		}
		else
			wait(&status);  }
	(void)st;
	(void)status;
	return (0);
}

/**
 *runcommand - takes the command lines and runs the appropriate function
 *@commands: command line
 *@buffer: the buffer for commands, passed here to be freed if exit is used
 *Return: Either a function call or NULL
 */

int (*runcommand(char **commands, char *buffer))(char **, char *)
{
	bi_t bia[] = {
		{"exit", sl_exit},
		{"env", sl_env},
		{NULL, NULL}
	};
	int i, bic = 2;
	int (*f)();

	if (buffer == NULL)
		buffer = " ";
	f = runexe;
	for (i = 0; i < bic; i++)
	{
		if (_strcmp(commands[0], bia[i].bi) == 0)
			return (bia[i].f);
	}
	return (f);
}

/**
 *main - entry point for the shell Sherlock
 *@ac: number of arguments
 *@av: array of arguments
 *@env: the enviroment
 *Return: 0
 */

int main(int ac, char **av, char **env)
{
	int fb = 0, status;
	size_t bufsize = 1024;
	char *buffer, **commands;
	struct stat st;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		buffer = (char *)malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			write(1, "Error: No Memory\n", 17);
			exit(1);
		}
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		fb = getline(&buffer, &bufsize, stdin);
		if (fb == EOF)
		{
			write(1, "\n", 1);
			free(buffer);
			exit(0);
		}
		buffer = watson(buffer);
		if (*buffer == '\n')
		{
			free(buffer);
		}
		else
		{
			commands = sherlock(buffer, " ");
			(*runcommand(commands, buffer))(commands, buffer);
			free(buffer);
			free_d_ptr(commands);
		}
	}
	(void)ac;
	(void)av;
	(void)env;
	(void)status;
	(void)st;
	return (0);
}
