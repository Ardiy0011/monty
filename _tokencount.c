#include "monty.h"

/**
 * _tokencount - Return the number of tokens.
 *
 * @tokens: The tokens to be analyzed.
 *
 * Return: The number of tokens found in @tokens.
 *
 **/
int _tokencount(char **tokens)
{
	int count = 0;

	while (tokens[count] != NULL)
	{
		count++;
	}

	return (count);
}
