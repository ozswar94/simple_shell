#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"


/**
* clean_newline - remove char newline in line
* @line: line of command
*
*/
void clean_newline(char *line)
{
	if (line[_strlen(line) - 1] == '\n')
		line[_strlen(line) - 1] = '\0';
}


/**
* clean_tab - replace char tabulation to space
* @line: line of command
*
*/
void clean_tab(char *line)
{
	unsigned int i;

	for (i = 0; line[i] != '\0'; i++)
		if (line[i] == '\t')
			line[i] = ' ';
}


/**
* simple_shell - main function for run simple_shell
* @name: name of programme
* Return: 2 if EOF, 0 Normaly
*/
int simple_shell(char *name)
{
	char *line = NULL;
	char *command_path = NULL;
	char **command = NULL;
	size_t len_line = 0;
	int counter = 1;

	while (1)
	{
		_printf("$ ");
		fflush(stdout);
		if (getline(&line, &len_line, stdin) == EOF)
		{
			free(line);
			_putchar('\n');
			return (2);
		}
		fflush(stdin);
		clean_newline(line);
		clean_tab(line);
		command = _strsplit(line, ' ');
		if (command == NULL)
			continue;

		if (check_built_in(command, line, counter, name) == 0)
		{
			command_path = search_path(command[0]);
			if (command_path != NULL)
				run_command(command_path, command);
			else
				_printf("%s: %d: %s: not found\n", name, counter, command[0]);
		}
		free_dptr(command);
		counter++;
	}
	return (0);
}


/**
* run_command - run command in new processus
* @command_path: absolute path of file
* @command: the line with argument
*
*/
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
