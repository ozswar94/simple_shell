#include <stdlib.h>
#include "shell.h"

void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_printf("%s\n", environ[i]);
		i++;
	}
}

char *_getenv(char *name)
{
	int i = 0;

	while (environ[i] != NULL && _strstr(environ[i], name) == NULL)
		i++;
	if (environ[i] != NULL)
	{
		return (_strstr(environ[i], name) + _strlen(name) + 1);
	}
	return (NULL);
}

