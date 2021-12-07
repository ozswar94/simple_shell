#include <stdlib.h>
#include "shell.h"


/**
* print_env - print environ varaible
* @command: command
* @line: llne of command
* @counter: counter of simple shell
* @name: name of program
*/
void print_env(char **command, char *line, int counter, char *name)
{
	int i = 0;

	(void)line;
	(void)command;
	(void)counter;
	(void)name;
	while (environ[i] != NULL)
	{
		_printf("%s\n", environ[i]);
		i++;
	}
}


/**
* _getenv - content of name env
* @name: variable env
* Return: content of variable env or NULL
*/
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

