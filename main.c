#include "shell.h"

/**
* main - main function which run simple_shell
* @argc: number of argument
* @argv: name of program + argument
*
* Return: status
*/

int main(int argc, char **argv)
{
	int status;

	(void)argc;
	status = simple_shell(argv[0]);

	return (status);
}
