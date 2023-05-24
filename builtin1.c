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
	int i;

	(void)cmd_num;
	if (args[1] == NULL)
		i = 0;
	else
		i = _atoi_exit(args[1]);
	if (i == -1)
	{
		_putstr("./hsh: ");
		_putstr(": exit: Illegal number: ");
		_putstr(args[1]);
		_putstr("\n");
	}
	else
	{
		free_arg(args);
		free(line_ptr);
		free(command);
		exit(i);
	}
}
