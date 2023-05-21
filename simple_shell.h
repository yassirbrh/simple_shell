#ifndef SHELL_MAIN
#define SHELL_MAIN

#include <stdio.h>
#define BUFFER_SIZE 2048
extern char **environ;
int _strlen(char *str);
void _strcpy(char *str1, char *str2);
ssize_t _getline(char **line_ptr, FILE *stream);
int _strcmp(char *str1, char *str2);
void inter_mode(void);
void non_inter_mode(void);
char *set_token(char *string, int index, int sec_index);
char **_strtok(char *str, char *delim);
int prompt(void);
char *command_format(char *string);
#endif /* SHELL_MAIN */
