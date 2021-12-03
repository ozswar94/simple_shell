#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"
#include "str_func.h"
#include "printf.h"

int simple_shell(void)
{
	char *line = NULL;
	char **command = NULL;
	size_t len_line = 0;
	int i, status_pid;

	while (1)
	{
		/*1 - print prompt and read line*/
		if (prompt(line, len_line) == -1)
		{
			_putchar('\n');
			free(line);
			break;
		}
		if (line == NULL)
			continue;
		/*2 - check if the command is in built-in, if is not a bultin check if the command is in PATH*/
		

		/*3 - run the command in a new processus and wait the parent processus*/


		/*4 - free memory alloc*/
		i = 0;
		if (command != NULL)
		{
			while (command[i] != NULL)
			{
				free(command[i]);
				i++;
			}
			free(command);
		}
		free(line);
		command = NULL;
		line = NULL;
	}
	return (0);
}
