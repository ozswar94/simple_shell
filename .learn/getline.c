#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

int _getchar()
{
	int c;
	read(STDIN_FILENO, &c, 1);
	return (c);
}

ssize_t _getline(char **lineptr, size_t *n)
{
	unsigned int i = 0;
	int c = 0;
	char *str = *lineptr;

	while ((c = _getchar()) != '\n' && *n > 0)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (i);
}


