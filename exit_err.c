#include <errno.h>
#include <stdio.h>
#include "printf.h"
#include <string.h>
#include <unistd.h>
#include "str_func.h"

/**
 * error - prints errors to standard error
 * @name: name of file
 * @command: command with the error
 * @counter: number of time the loop was made
 */

void error_exit(char *name, char **command, int counter)
{

	write(STDERR_FILENO, name, strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, " exit: Illegal number: "); 	
	write(STDERR_FILENO, command[0], strlen(command[0]);
	write(STDERR_FILENO, "\n", 1);
}
