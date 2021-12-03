#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "printf.h"
#include "str_func.h"

int prompt(char *line, size_t size)
{
	int len_read;
	int i;

	_printf("$ ");
	len_read = getline(&line, &size, stdin);
	check_space()
	return (len_read);
}

void check_space(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
}