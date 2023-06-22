#include "monty.h"

/**
 * _strlen - Determine the length for a string.
 *
 * @str: The given string.
 *
 * Return: The number of characters in the given
 * string.
 *
 **/
int _strlen(char *str)
{
	int length = 0, index = 0;

	while (str[index] != '\0')
	{
		index++;
	}
	length = index;

	return (length);
}
