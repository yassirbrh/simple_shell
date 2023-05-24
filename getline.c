#include "simple_shell.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * _getline - Function
 *
 * Description: read a line from the user input.
 *
 * @line_ptr: Pointer to the string that will contain the readed line.
 * @n: Pointer to the size of buffer.
 * @stream: Pointer to the filestream (in our case input stream).
 *
 * Return: the length of the string readed.
 */
ssize_t _getline(char **line_ptr, size_t *n, FILE *stream)
{
	ssize_t bytes_read;

	bytes_read = read(fileno(stream), *line_ptr, *n);
	if (bytes_read == -1)
	{
		perror("read");
		return (-1);
	}
	return (bytes_read);

}
