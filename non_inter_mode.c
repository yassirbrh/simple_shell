#include "simple_shell.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * non_inter - Function
 *
 * Description: Execute the command in non-interactive mode.
 *
 * @line_ptr: Pointer to the user input.
 * @env: Pointer to the array containing the environment variables.
 *
 * Return: No return because it's a void function.
 */
void non_inter(char *line_ptr, char **env)
{
	char **commands = _strtok(line_ptr, "\n"), **args;
	int i = 0, cmd_found = 0, status;
	static int cmd_num;
	char *command;

	while (commands[i] != NULL)
	{
		if (isStringEmpty(commands[i]))
		{
			free(commands[i]);
			commands[i] = NULL;
		}
		i++;
	}
	i = 0;
	while (commands[i] != NULL)
	{
		command = command_format(commands[i]);
		args = _strtok(command, " ");
		if (_strcmp("exit", args[0]) == 0)
		{
			free_arg(commands);
			exit_shell(args, line_ptr, command, cmd_num);
		}
		cmd_found = builtin_cmd(args, env);
		if (!cmd_found)
			execute_command(args, env, &status);
		free_arg(args);
		free(command);
		cmd_num++;
		i++;
	}
	free(line_ptr);
	free_arg(commands);

}
/**
 * non_inter_mode - Function
 *
 * Description: Represents the non-interactive mode of the simple shell.
 *
 * Return: No return because it's a void function.
 */
void non_inter_mode(void)
{
	pid_t my_pid = getpid();

	prompt(my_pid);
}
