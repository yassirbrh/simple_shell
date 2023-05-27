#include "simple_shell.h"

/**
 * _atoi_exit - Function
 *
 * Description: Returns the conversion of the first argument of exit
 *              to a number.
 *
 * @str: Pointer to the string.
 *
 * Return: The number from the argument.
 */
int _atoi_exit(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		else
			return (-1);
		i++;
	}

	return (sign * result);
}
