#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getenv(char *name)
{
	extern char **environ;
	int i = 0;

	while (environ[i] != NULL && strstr(environ[i], name) == NULL)
		i++;
	if (environ[i] != NULL)
	{
		return (strstr(environ[i], name) + strlen(name) + 1);
	}
	return (NULL);
}

