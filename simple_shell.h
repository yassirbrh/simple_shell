#ifndef SHELL_MAIN
#define SHELL_MAIN

#include <stdio.h>
ssize_t _getline(char **line_ptr, FILE *stream);
void inter_mode(char **line_ptr);
void non_inter_mode(char **line_ptr);
#endif /* SHELL_MAIN */
