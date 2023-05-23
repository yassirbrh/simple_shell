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
				exit(1);
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
	free(args);
}
/**
 * prompt - Function
 *
 * Description: The main actor of the shell program.
 *
 * Return: 0 (Sucess)
 *         1 (Exit)
 */
int prompt(void)
{
	char **args, **env = environ;
	int status, ret_value;
	char *line_ptr = malloc(sizeof(char) * BUFFER_SIZE);

	if (_getline(&line_ptr, stdin) == 0)
		return (1);
	line_ptr = command_format(line_ptr);
	args = _strtok(line_ptr, " ");
	/*add exit*/
	/*while (args)*/

		if (_strcmp(args[0], "exit") == 0)
			exit(1);

	ret_value = execute_command(args, env, &status);
	free(line_ptr);
	free_arg(args);
	return (ret_value);
}
