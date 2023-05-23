#include "simple_shell.h"
#include <unistd.h>
#include <stdlib.h>
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
