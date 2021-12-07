#include <stdlib.h>
#include "shell.h"


/**
* exit_sh - exit simple shell
* @command: command
* @line: llne of command
* @counter: counter of simple shell
* @name: name of program
*/
void exit_sh(char **command, char *line, int counter, char *name)
{
	int status = 0;
	(void)name;
	status = _atoi(command[1]);
	if (status != 0)
	{
		free(line);
		free_dptr(command);
		exit(status);
	}
	else
	{
		_printf("%s: %d: exit: Illegal nunber: %s\n", name, counter, command[1]);
	}
}

