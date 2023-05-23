#include "simple_shell.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * initialize_string - Function
 *
 * Description: Initialises the string.
 *
 * @str: Pointer to the string.
 * @str_len: The length of the string.
 *
 * Return: No return because it's a void function.
 */
void initialize_string(char *str, int str_len)
{
	int i;

	for (i = 0; i < str_len; i++)
	{
		str[i] = '\0';
	}
}
/**
 * count_tokens - Function
 *
 * Description: Count tokens from the string depending on the delimiter.
 *
 * @str: Pointer to the string.
 * @str_len: The length of the string.
 * @delim: Pointer to the delimiter.
 *
 * Return: The count of tokens.
 */
int count_tokens(char *str, int str_len, char *delim)
{
	int i, j;
	int delim_len = _strlen(delim);
	int match, token_count = 0;

	for (i = 0; i < str_len; i++)
	{
		match = 1;
		for (j = 0; j < delim_len; j++)
		{
			if (str[i + j] != delim[j])
			{
				match = 0;
				break;
			}
		}
		if (match)
		{
			token_count++;
			i += delim_len - 1;
		}
	}

	return (token_count);
}
/**
 * extract_tokens - Function
 *
 * Description: Extract tokens from the string depending on the delimiter.
 *
 * @str: Pointer to the string.
 * @str_len: The length of the string.
 * @delim: Pointer to the delimiter.
 * @tokens: Pointer to the array of the tokens.
 *
 * Return: No return because it's a void function.
 */
void extract_tokens(char *str, int str_len, char *delim, char **tokens)
{
	int j;
	int delim_len = _strlen(delim);
	int match, token_index = 0, index = 0, sec_index = 0;

	while (index < str_len)
	{
		if (str[index] == delim[0])
		{
			match = 1;
			for (j = 0; j < delim_len; j++)
			{
				if (str[index + j] != delim[j])
				{
					match = 0;
					break;
				}
			}
			if (match)
			{
				tokens[token_index++] = set_token(str, index, sec_index);
				index += delim_len;
				sec_index = index;
			}
			else
			{
				index++;
			}
		}
		else
		{
			index++;
		}
	}

	tokens[token_index++] = set_token(str, index, sec_index);
	tokens[token_index] = NULL;
}
/**
 * _strtok - Function
 *
 * Description: Creates an array of tokens depending on the delimiter.
 *
 * @str: Pointer to the string.
 * @delim: Pointer to the delimiter.
 *
 * Return: Array of tokens created depending on the delimiter.
 */
char **_strtok(char *str, char *delim)
{
	char *string;
	int str_len = _strlen(str);
	int token_count;
	char **tokens;

	if (str == NULL)
		return (NULL);
	string = malloc(sizeof(char) * (str_len + 1));
	_strcpy(str, string);
	token_count = count_tokens(string, str_len, delim);
	tokens = malloc(sizeof(char *) * (token_count + 2));
	extract_tokens(string, str_len, delim, tokens);
	free(string);

	return (tokens);
}
