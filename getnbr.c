#include "str_func.h"

/**
 * my_getnbr - print numbers (as char)
 * @str: number to print
 *
 * Return: str as int
 */

int my_getnbr(char *str)
{
	int number;
	int i;
	int n;

	i = 0;
	number = 0;
	n = 1;

	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		n = -1 * n;
		i++;
	}

	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		number = (number * 10) + (str[i] - '0');
		i += 1;
	}

	return (number * n);
}

