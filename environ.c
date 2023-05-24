#include "simple_shell.h"
/**
 * printenv - Function
 *
 * Description: Prints all the environment variables.
 *
 * @args: Pointer to the array of arguments.
 * @env: Pointer to the array of environment variables.
 *
 * Return: No return because it's a void function.
 */
void printenv(char **args, char **env)
{
	int i = 0;

	if (args[1] != NULL)
		perror("env: ");
	else
	{
		while (env[i] != NULL)
		{
			_putstr(env[i]);
			_putstr("\n");
			i++;
		}
	}
}
