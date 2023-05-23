#include "simple_shell.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * inter_mode - Function
 *
 * Description: Represents the interactive mode of the shell program.
 *
 * Return: No return because it's a void function.
 */
void inter_mode(void)
{
	pid_t my_pid = getpid();

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		if (prompt(my_pid) == 1)
			break;
	}
	printf("\n");
}
