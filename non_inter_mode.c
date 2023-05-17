#include "simple_shell.h"
#include <unistd.h>
/**
 * non_inter_mode - Function
 *
 * Description: Represents the non-interactive mode of the simple shell.
 *
 * @line_ptr: Pointer to the string containing the command.
 *
 * Return: No return because it's a void function.
 */
void non_inter_mode(char **line_ptr)
{
	prompt(*line_ptr);
}
