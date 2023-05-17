#ifndef SHELL_MAIN
#define SHELL_MAIN

#include <stdio.h>
extern char **environ;
int _strlen(char *str);
ssize_t _getline(char **line_ptr, FILE *stream);
void inter_mode(char **line_ptr);
void non_inter_mode(char **line_ptr);
char *_strtok(char *str, char *delim);
int prompt(char *line_ptr);
char *command_format(char *string);
#endif /* SHELL_MAIN */
