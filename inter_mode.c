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
	while (1)
	{
		printf("$ ");
		fflush(stdout);
		if (prompt() == 1)
			break;
	}
	printf("\n");
}
