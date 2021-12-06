#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>
#include <unistd.h>
#include "shell.h"

char *search_path(char *command)
{
	int i;
	struct stat buf;
	char *command_path;
	char **path_directory;

	path_directory = _strsplit(_getenv("PATH"), ':');
	if (path_directory == NULL)
		return (NULL);

	i = 0;
	while (path_directory[i] != NULL)
	{
		command_path = malloc(_strlen(command) + _strlen(path_directory[i]) + 2);
		if (command_path == NULL)
			return (NULL);

		_strcpy(command_path, path_directory[i]);
		_strcat(command_path, "/");
		_strcat(command_path, command);

		if (stat(command_path, &buf) == 0)
		{
			free_dptr(path_directory);
			return (command_path);
		}
		free(command_path);
		i++;
	}
	free_dptr(path_directory);
	return (NULL);
}
