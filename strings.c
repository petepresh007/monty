#include "monty.h"

/**
 * _isdigit - Checks if a character is a decimal number(0 -9)
 * @str: string to check
 * Return: The string or NULL if it fails
*/
char *_isdigit(char *str)
{
	if (*str == '-')
		str++;

	while (*str != '\0')
	{
		if (*str == '.')
			return (NULL);
		if (*str < '0' || *str > '9')
			return (NULL);
		str++;
	}
	return (str);
}


/**
 * isempty - Checks if a string is blank or a newline or a comment (#)
 * @str: string to check
 * Return: 1 if true, else 0
*/
int isempty(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '#')
			return (1);
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}

	return (1);
}
