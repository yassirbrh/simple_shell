#include "simple_shell.h"
#include <unistd.h>
/**
 * inter_mode - Function
 *
 * Description: Represents the interactive mode of the shell program.
 *
 * @line_ptr: Pointer to the string containing the command.
 *
 * Return: No return because it's a void function.
 */
void inter_mode(char **line_ptr)
{

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		if (_getline(line_ptr, stdin) == 0)
			break;
	}
	printf("\n");
}
