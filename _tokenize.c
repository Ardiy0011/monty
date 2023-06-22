#include "monty.h"

/**
 * _tokenize - Generate tokens from a given string.
 *
 * @str: The given string
 * @exit_code: The memory address to the exit code.
 *
 * Return: A pointer to pointers made of tokens
 * from @str.
 *
 **/
char **_tokenize(char *str, int *exit_code)
{
	int index = 0;
	char *token = NULL;
	char **tokens = NULL;

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		_error(exit_code, 0, "Error: malloc failed");
		return (NULL);
	}
	token = strtok(str, DELIMITERS);
	while (token != NULL)
	{
		if (index == 2)
		{
			break;
		}
		tokens[index] = token;
		token = strtok(NULL, DELIMITERS);
		index++;
	}
	tokens[index] = NULL;

	return (tokens);
}
