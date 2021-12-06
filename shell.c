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
	char *command_path;
	char **command;
	size_t len_line = 0;

	while (1)
	{
/*1 - print prompt and read line*/
		_printf("$ ");
		fflush(stdout);
		if (getline(&line, &len_line, stdin) == EOF)
		{
			free(line);
			_putchar('\n');
			return (1);
		}
		fflush(stdin);
		if (line[0] == '\n')
			continue;
		clean_line(line);
		command = _strsplit(line, ' ');
		if (command == NULL)
			continue;
/*
* 2 - check if the command is in built-in,
* if is not a bultin check if the command is in PATH
*/
		if (check_built_in(command[0]) == 0)
		{
/*3 - run the command in a new processus and wait the parent processus*/
			command_path = search_path(command[0]);
			if (command_path != NULL)
			{
				_printf("%s: command found\n", command[0]);
				free(command_path);
			}
			else
				_printf("%s: command not found\n", command[0]);
		}
/*4 - free memory alloc*/
		/*clean_dptr(command);*/
	}
	return (0);
}

