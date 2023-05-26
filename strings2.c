#include <stdlib.h>
#include "simple_shell.h"
/**
 * isStringEmpty - Function
 *
 * Description: Check if a string is empty.
 *
 * @str: Pointer to the string.
 *
 * Return: 1 (empty)
 *         0 (not empty)
 */
int isStringEmpty(char *str)
{
	if (str == NULL)
		return (1);

	while (*str != '\0')
	{
		if (*str != ' ' && *str != '\t' && *str != '\n')
			return (0);
		str++;
	}
	return (1);
}
/**
 * command_format - Function
 *
 * Description: Format the command to make it runnable.
 *
 * @string: Pointer to the string containing the command.
 *
 * Return: Pointer to the reformatted string.
 */
char *command_format(char *string)
{
	int i = 0, j = 0, str_len = _strlen(string);
	char *str = malloc(sizeof(char) * (str_len + 1));

	if (str == NULL)
		return (NULL);
	while (string[i] != '\n' && string[i] != '\0')
	{
		if (string[i] == ' ' || string[i] == '\t')
		{
			str[j] = ' ';
			while (string[i] == ' ' || string[i] == '\t')
				i++;
			if (j == 0)
			{
				str[j] = string[i];
				i++;
			}
			i--;
		}
		else
			str[j] = string[i];
		i++;
		j++;
	}
	str[j] = '\0';
	if (str[j - 1] == ' ')
	{
		str[j - 1] = '\0';
		j--;
	}
	return (str);
}
