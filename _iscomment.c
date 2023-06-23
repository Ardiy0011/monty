#include "monty.h"

/**
 * _iscomment - Check whether the given string
 * is a comment.
 *
 * @str: The given string. This is also equivalent
 * to the line read from a file.
 *
 * Return: IS_COMMENT_YES if @str is a line starting
 * with # (a comment) otherwise IS_COMMENT_NO.
 *
 **/
int _iscomment(char *str)
{
	int index = 0, exit_code = IS_COMMENT_NO;

	while (str[index] != '\0')
	{
		if (str[index] == ' ' || str[index] == '\t')
		{
			index++;
			continue;
		}
		if (str[index] == '#')
		{
			exit_code = IS_COMMENT_YES;
		}
		break;
	}

	return (exit_code);
}
