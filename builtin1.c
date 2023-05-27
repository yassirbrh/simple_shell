#include "simple_shell.h"
#include <stdlib.h>
/**
 * exit_shell - Function
 *
 * Description: Exists the shell.
 *
 * @args: Pointer to the array containing the arguments.
 * @line_ptr: Pointer to a string to free.
 * @command: Pointer to a string to free.
 * @cmd_num: The ID of the command.
 *
 * Return: No return because it's a void function.
 */
void exit_shell(char **args, char *line_ptr, char *command, int cmd_num)
{
	int i, cmd = cmd_num + 1;

	if (args[1] == NULL)
		i = 0;
	else
		i = _atoi_exit(args[1]);
	if (i < 0)
		fprintf(stderr, "./hsh: %d: exit: Illegal number: %s\n", cmd, args[1]);
	else
	{
		free_arg(args);
		free(line_ptr);
		free(command);
		exit(i % 256);
	}
}
