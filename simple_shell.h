#ifndef SHELL_MAIN
#define SHELL_MAIN

#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 2048
/*
 * The environ is an array of all environment variables of OS.
 */
extern char **environ;
/**
 * struct cmdtofunc - Function
 *
 * Description: Links the commands with function pointers.
 *
 * @command_str: Command string.
 * @f: Function pointer linked to it.
 *
 */
typedef struct cmdtofunc
{
	char *command_str;
	void (*f)(char **args);
} cmdtofunc;
/*
 * String functions used.
 */
int _strlen(char *str);
void _strcpy(char *str1, char *str2);
int _strcmp(char *str1, char *str2);
ssize_t _getline(char **line_ptr, size_t *n, FILE *stream);
void inter_mode(void);
void non_inter_mode(void);
char *set_token(char *string, int index, int sec_index);
char **_strtok(char *str, char *delim);
int prompt(pid_t my_pid);
char *command_format(char *string);
void free_arg(char **args);
void exit_shell(char **args, char *line_ptr, char *command);
#endif /* SHELL_MAIN */
