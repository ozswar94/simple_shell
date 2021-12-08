#include <unistd.h>
#include <stdio.h>
#include "shell.h"
#include "printf.h"

/**
* prompt - prompt of simple shell
*/

void prompt(void)
{
	fflush(stdout);
	if (isatty(STDIN_FILENO))
		_printf("$ ");
	fflush(stdin);
}

