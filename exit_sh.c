#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "format.h"
#include "printf.h"
#include "shell.h"
#include "str_func.c"

/**
 * exit_sh - exit the shell
 * @status: 0 is success, 1 is an error
 */

void exit_sh(int status, char *line)
{
	size_t size = 1024;

	char *buf;
	char *exit = "exit";

	if (status == 0)
	{
		free(line);
		if(line == exit)
			exit(status);
	}
	
	else
		exit (status);

}

