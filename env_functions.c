#include <stdlib.h>
#include "shell.h"
#include "printf.h"


void print_env()
{
	extern char **environ;
	int i = 0;

	while (environ[i] != NULL)
	{
		_printf("%s", environ[i]);
		i++;
	}
}

char *_getenv(char *name)
{
	extern char **environ;
	int i = 0;

	while (environ[i] != NULL && _strstr(environ[i], name) == NULL)
		i++;
	if (environ[i] != NULL)
	{
		return (_strstr(environ[i], name) + _strlen(name));
	}
	return (NULL);
}

