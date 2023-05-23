#include "simple_shell.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * exit_shell - Function
 *
 * Description: Exists the shell.
 *
 * @args: Pointer to the array containing the arguments.
 * @line_ptr: Pointer to a string to free.
 * @command: Pointer to a string to free.
 *
 * Return: No return because it's a void function.
 */
void exit_shell(char **args, char *line_ptr, char *command)
{
	int i;

	if (args[1] == NULL)
		i = 0;
	else
		i = 1;
	free_arg(args);
	free(line_ptr);
	free(command);
	exit(i);
}
