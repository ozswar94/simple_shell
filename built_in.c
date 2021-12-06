#include "shell.h"

int check_built_in(char *command)
{
	int i = 0;
	built_in_t command_built_in[] = {
		{"env", print_env},
		{"\0", NULL},
	};

	while (command_built_in[i].command[0] != '\0')
	{
		if (_strcmp(command_built_in[i].command, command) == 0)
		{
			command_built_in[i].built_in();
			return (1);
		}
		i++;
	}
	return (0);
}

