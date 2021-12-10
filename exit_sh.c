#include <stdlib.h>
#include <stdio.h>
#include "shell.h"
#include "error.h"


/**
* exit_sh - exit simple shell
* @command: command
* @line: llne of command
* @counter: counter of simple shell
* @name: name of program
* Return: 2 if error exit
*/
int exit_sh(char **command, char *line, int counter, char *name)
{
	int status = 0;

	status = _atoi(command[1]);
	if (status >= 0 || command[1] == NULL)
	{
		free(line);
		free_dptr(command);
		exit(status);
	}
	else
	{
		error_exit(name, command, counter);
	}
	return (2);
}
