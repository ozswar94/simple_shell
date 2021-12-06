#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/stat.h>
#include <unistd.h>
#include "shell.h"

char *search_path(char *command)
{
	int i;
	struct stat buf;
	char *command_path = NULL;
	char **path_directory = NULL;

	path_directory = _strsplit(_getenv("PATH"), ':', path_directory);
	if (path_directory == NULL)
		return (NULL);

	i = 0;
	while (path_directory[i] != NULL)
	{
		command_path = malloc(_strlen(command) + _strlen(path_directory[i]) + 2);
		if (command_path == NULL)
			return (NULL);
		printf("!%p\n", path_directory[i]);
		_strcpy(command_path, path_directory[i]);
		_strcat(command_path, "/");
		_strcat(command_path, command);
		printf("!%p\n", path_directory[i]);
		if (stat(command_path, &buf) == 0)
		{
			for (i = 0; path_directory[i]; i++)
				_printf("-%s\n", path_directory[i]);
			_printf("TEST 4\n");
			free_dptr(path_directory);
			_printf("TEST 5\n");
			_printf("-%s\n", command_path);
			return (command_path);
		}
		free(command_path);
		i++;
	}
	free_dptr(path_directory);
	return (NULL);
}
