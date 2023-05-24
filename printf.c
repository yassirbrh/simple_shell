#include "simple_shell.h"
/**
 * _putstr - Function
 *
 * Description: Prints the string.
 *
 * @str: Pointer to the string.
 *
 * Return: No return because it's a void function.
 */
void _putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		write(STDOUT_FILENO, &str[i], 1);
		i++;
	}
}
