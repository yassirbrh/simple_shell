#include "simple_shell.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * _strlen - Function
 *
 * Description: Returns the length of the string
 *
 * @str: Pointer to the string.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
		i++;

	return (i);
}

/**
 * _strcpy - Function
 *
 * Description: Copies a string into another variable.
 *
 * @str1: Pointer to the string to copy.
 * @str2: Pointer to the new created string.
 *
 * Return: No return because it's a void function.
 */
void _strcpy(char *str1, char *str2)
{
	int i = 0;

	while (*(str1 + i) != '\0')
	{
		*(str2 + i) = *(str1 + i);
		i++;
	}
	*(str2 + i) = '\0';

}
/**
 * _strcmp - Function
 *
 * Description: Compares a string with another.
 *
 * @str1: Pointer to the first string.
 * @str2: Pointer to the second string.
 *
 * Return: 0 if the strings are the same.
 *         1 if the strings are differents.
 */
int _strcmp(char *str1, char *str2)
{
	 int i = 0;

	while (*(str1 + i) != '\0')
	{
		if (*(str1 + i) != *(str2 + i))
			return (1);
		i++;
	}
	return (0);
}
/**
 * set_token - Function
 *
 * Description: Set the token after splitting it from the string.
 *
 * @string: Pointer to the string.
 * @index: The index that is incrementing.
 * @sec_index: The index to start from.
 *
 * Return: The token after splitting from the string.
 */
char *set_token(char *string, int index, int sec_index)
{
	int i;
	char *token = malloc(sizeof(char) * (index - sec_index + 1));

	for (i = sec_index; i < index; i++)
		token[i - sec_index] = string[i];
	token[i - sec_index] = '\0';
	return (token);
}
/**
 * _strtok - Function
 *
 * Deescripion: Split a string depending on a delimiter.
 *
 * @str: Pointer to the string.
 * @delim: The delimiter.
 *
 * Return: Part of the string depending of the delimiter.
 */
char *_strtok(char *str, char *delim)
{
	static char *string;
	char *buf_delim = malloc(sizeof(char) * (_strlen(delim) + 1));
	char *token = NULL;
	static int index, sec_index, i;

	if (str == NULL)
	{
		if (string == NULL || *(string + index) == '\0')
		{
			free(string);
			free(buf_delim);
			index = 0;
			sec_index = 0;
			return (NULL);
		}
	}
	else
	{
		string = malloc(sizeof(char) * (_strlen(str) + 1));
		_strcpy(str, string);
	}
	while (*(string + index) != '\0')
	{
		if (*(string + index) == delim[0])
		{
			for (i = index; i < index + _strlen(delim); i++)
				buf_delim[i - index] = string[i];
			buf_delim[i - index] = '\0';
			if (_strcmp(delim, buf_delim) == 0)
			{
				token = set_token(string, index, sec_index);
				index += _strlen(delim);
				sec_index = index;
				return (token);
			}
		}
		index++;
	}
	token = set_token(string, index, sec_index);
	return (token);
}
