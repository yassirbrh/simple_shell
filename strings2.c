#include <stdlib.h>
#include "simple_shell.h"
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
	int i = 0, j = 0;
	char *str = malloc(sizeof(char) * _strlen(string) + 1);

	while (string[i] != '\n')
	{
		if (string[i] == ' ' || string[i] == '\t')
		{
			str[j] = ' ';
			while (string[i] == ' ' || string[i] == '\t')
			{
				i++;
			}
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
	if (str[j - 1] == '\n')
	{
		str[j - 1] = '\0';
		j--;
	}
	if (str[j - 1] == ' ')
	{
		str[j - 1] = '\0';
		j--;
	}
	return (str);
}
