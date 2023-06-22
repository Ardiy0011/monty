#include "monty.h"

/**
 * _strrev - Reverse the given string.
 *
 * @str: The given string to reverse.
 * @exit_code: The memory address to the exit code.
 *
 * Return: The reversed string.
 *
 **/
char *_strrev(char *str, int *exit_code)
{
	int length = 0, index = 0;
	char *new_str = NULL;

	length = _strlen(str);
	new_str = malloc(sizeof(char) * (length + 1));
	if (new_str == NULL)
	{
		_error(exit_code, 0, "Error: malloc failed");
		return (NULL);
	}
	while (length > 0)
	{
		new_str[index] = str[length - 1];
		length--;
		index++;
	}
	free(str);
	new_str[index] = '\0';

	return (new_str);
}
