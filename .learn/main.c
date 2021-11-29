#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

int main(void)
{
	char *buff;
	char **words = NULL;
	int i = 0;
	size_t len = 1024;

	buff = malloc(1024);
	if (buff == NULL)
		return (-1);
	write(1 ,"$ ", 2);
	_getline(&buff, &len);
	words = strsplit(buff, ' ');
	if (words == NULL)
		return 0;
	while (words[i] != NULL)
		printf("%s\n", words[i++]);
	i = 0;
	while (words[i++] != NULL)
		free(words[i]);
	free(words);
	free(buff);
	return (0);
}
