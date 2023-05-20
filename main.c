#include "simple_shell.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * Description: Entry point for the shell program.
 *
 * Return: 0 Success (Always)
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
		inter_mode();
	else
		non_inter_mode();
	return (0);
}
