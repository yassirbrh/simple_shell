#include "simple_shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
/**
 * prompt - Function
 *
 * Description: The main actor of the shell program.
 *
 * @line_ptr: Pointer to the command line.
 *
 * Return: 0 (Sucess)
 *         1 (Exit)
 */
int prompt(char *line_ptr)
{
	char **env = environ;
	char **args;
	int argc = 0, i, status;
	char *command;
	pid_t pid;

	if (_getline(&line_ptr, stdin) == 0)
		return (1);
	line_ptr = command_format(line_ptr);
	command = _strtok(line_ptr, " ");
	while (command != NULL)
	{
		argc++;
		command = _strtok(NULL, " ");
	}
	args = malloc(sizeof(char *) * (argc + 1));
	args[0] = _strtok(line_ptr, " ");
	for (i = 1; i < argc; i++)
		args[i] = _strtok(NULL, " ");
	args[argc] = NULL;
	i = 0;
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
		wait(&status);
	/*
	   printf("%d, ",_strlen(args[0]));
	   while (i < _strlen(args[0]))
	   {
	   printf("%d ", args[0][i]);
	   i++;
	   }
	   */
	free(args);
	free(command);
	free(line_ptr);
	return (0);
}
