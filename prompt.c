#include "simple_shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
/**
 * execute_command - Function
 *
 * Description: Execute the command.
 *
 * @args: Pointer to the array of the strings that are parts of the command.
 * @env: Pointer to the array of environment variables.
 * @status: Pointer to the status variable.
 *
 * Return: No return because it's a void function.
 */
int execute_command(char **args, char **env, int *status)
{
	pid_t pid;

	if (access(args[0], X_OK) == 0)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			return (1);
		}
		else if (pid == 0)
		{
			if (execve(args[0], args, env) == -1)
			{
				perror("./hsh");
				exit(127);
			}
		}
		else
			wait(status);
	}
	else
		perror("./hsh");
	return (0);
}
/**
 * builtin_cmd - Function
 *
 * Description: Execute the builtin commands.
 *
 * @args: Pointer to the array containing the arguments.
 * @env: Pointer to the array of environment variables.
 *
 * Return: 0 if the command not found.
 *         1 if the command is found.
 */
int builtin_cmd(char **args, char **env)
{
	int cmd_found = 0;

	if (_strcmp("env", args[0]) == 0)
	{
		printenv(args, env);
		cmd_found = 1;
	}
	return (cmd_found);
}
/**
 * free_arg - Function
 *
 * Description: Frees the arguments buffers.
 *
 * @args: Pointer to the array containing the arguments.
 *
 * Return: No return because it's a void function.
 */
void free_arg(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args[i]);
	free(args);
}
/**
 * prompt - Function
 *
 * Description: The main actor of the shell program.
 *
 * @my_pid: PID of the shell program.
 *
 * Return: 0 (Sucess)
 *         1 (Exit)
 */
int prompt(pid_t my_pid)
{
	char **args, **env = environ;
	static int cmd_num, status;
	size_t n = BUFFER_SIZE;
	int ret_value = 0, cmd_found = 0;
	char *line_ptr = malloc(sizeof(char) * BUFFER_SIZE), *command;

	if (line_ptr == NULL)
		return (1);
	initialize_string(line_ptr, BUFFER_SIZE);
	(void)my_pid;
	if (_getline(&line_ptr, &n, STDIN_FILENO) == 0)
		return (1);
	if (isStringEmpty(line_ptr))
	{
		free(line_ptr);
		return (0);
	}
	if (isatty(STDIN_FILENO))
	{
		command = command_format(line_ptr);
		args = _strtok(command, " ");
		if (_strcmp("exit", args[0]) == 0)
		{
			exit_shell(args, line_ptr, command, cmd_num, &status);
			cmd_found = 1;
		}
		else
			cmd_found = builtin_cmd(args, env);
		if (!cmd_found)
			ret_value = execute_command(args, env, &status);
		free(line_ptr);
		free(command);
		cmd_num++;
		free_arg(args);
	}
	else
		non_inter(line_ptr, env);
	return (ret_value);
}
