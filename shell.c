#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

/*Remove new line*/
void clean_line(char *command)
{
	if (command[_strlen(command) - 1] == '\n')
		command[_strlen(command) - 1] = '\0';
}

int simple_shell(void)
{
	char *line = NULL;
	char *command_path = NULL;
	char **command = NULL;
	size_t len_line = 0;

	while (1)
	{
		_printf("$ ");
		fflush(stdout);
		if (getline(&line, &len_line, stdin) == EOF)
		{
			free(line);
			_putchar('\n');
			return (1);
		}
		fflush(stdin);
		clean_line(line);
		command = _strsplit(line, ' ');
		if (command == NULL)
			continue;

		if (check_built_in(command[0]) == 0)
		{
			command_path = search_path(command[0]);
			if (command_path != NULL)
				run_command(command_path, command);
			else
				_printf("%s: command not found\n", command[0]);
		}
		free_dptr(command);
	}
	return (0);
}

void run_command(char *command_path, char **command)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(command_path, command, NULL) == -1)
		{
			_printf("Error: command\n");
		}
	}
	else
	{
		wait(&status);
		free(command_path);
	}
}
