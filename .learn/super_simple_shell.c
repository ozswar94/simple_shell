#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

int main(void)
{
	pid_t child;
	int status;
	char **argv;
	char *line;
	size_t len = 1024;
	int i;

	while (1)
	{
		line = malloc(sizeof(char) * len);
		write(1, "#cisfun$ ", 9);
		fflush(stdout);
		_getline(&line, &len);
		argv = strsplit(line, ' ');
		free(line);
		if (argv == NULL)
		{
			free(argv);
			continue;
		}

		child = fork();
		if (child == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
			i = 0;

			while (argv[i] != NULL)
			{
				free(argv[i]);
				i++;
			}
			free(argv);
		}
	}
	return (0);
}
