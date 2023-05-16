#include "simple_shell.h"
#include <unistd.h>
/**
 * main - Entry point
 *
 * Description: Entry point for the shell program.
 *
 * Return: 0 Success (Always)
 */
int main(void)
{
	char *line_ptr = NULL;

	if (isatty(STDIN_FILENO))
		inter_mode(&line_ptr);
	else
		non_inter_mode(&line_ptr);
	return (0);
}
