#include <stdlib.h>
#include <stdio.h>
#include "str_func.h"
#include "printf.h"
/**
* _strlen - determine se sizeof ol string
* @s: string
* Return: the size of s
*/

unsigned int _strlen(char *s)
{
	unsigned int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
* strtow - Each element of this array should contain
* a single word, null-terminated
* @str: string
* Return: a pointer to an array of strings (words)
*/

char **_strsplit(char *str, int c, char **tab_word)
{
	unsigned int i, j, k;
	unsigned int word = 0;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			word++;
	if (str == NULL || _strlen(str) == 0 || i == word)
		return (NULL);
	tab_word = malloc(sizeof(char *) * (word + 1));
	printf("ptr=%p\n", (void *)tab_word);
	if (tab_word == NULL)
		return (NULL);
	k = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] && str[i + j] != c)
			j++;
		if (j == 0)
		{
			i++;
			continue;
		}
		tab_word[k] = malloc(sizeof(char) * (j + 1));
		if (tab_word[k] == NULL)
		{
			for (j = 0; j < k; j++)
				free(tab_word[j]);
			free(tab_word);
			return (NULL);
		}
		for (j = 0; str[i + j] && str[i + j] != c; j++)
			tab_word[k][j] = str[i + j];
		tab_word[k][j] = '\0';
		_printf("-%s\n", tab_word[k]);
		k++;
		i += j;
	}
	tab_word[k] = NULL;
	printf("ptr=%p\n", (void *)tab_word);
	for (i = 0; tab_word[i] != NULL; i++)
		_printf("%s\n", tab_word[i]);
	return (tab_word);
}

void free_dptr(char **ptr)
{
	int i;

	i = 0;
	_printf("TEST 6\n");
	printf("$ptr=%p\n", (void *)ptr);
	while (ptr[i] != NULL)
	{
		printf("$ptr=%p\n", (void *)ptr[i]);
		printf("ptr[%d]= %s\n", i, ptr[i]);
		free(ptr[i]);
		_printf("%d\n", i);
		i++;
	}
	_printf("TEST 7\n");
	free(ptr);
}