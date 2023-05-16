#include "simple_shell.h"
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
/**
 * _getline - Function
 *
 * Description: read a line from the user input.
 *
 * @line_ptr: Pointer to the string that will contain the readed line.
 * @stream: Pointer to the filestream (in our case input stream).
 *
 * Return: the length of the string readed.
 */
ssize_t _getline(char **line_ptr, FILE *stream)
{
	ssize_t bytes_read;

	*line_ptr = malloc(BUFFER_SIZE * sizeof(char));
	bytes_read = read(fileno(stream), *line_ptr, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		perror("read");
		return (-1);
	}
	return (bytes_read);

}
