#include "monty.h"

/**
 * _isnumber - Determine whether the given string is
 * made of digits only.
 *
 * @str: The string to validate.
 *
 * Return: IS_NUMBER if @str contains digits only
 * otherwise IS_ALPHA.
 *
 **/
int _isnumber(char *str)
{
	char *digits = "-0123456789";
	int d_index = 0, s_index = 0;
	int result = IS_ALPHA;

	while (str[s_index] != '\0')
	{
		result = IS_ALPHA;
		d_index = 0;
		while (digits[d_index] != '\0')
		{
			if (str[s_index] == digits[d_index])
			{
				result = IS_NUMBER;
				break;
			}
			d_index++;
		}
		if (result == IS_ALPHA)
		{
			break;
		}
		s_index++;
	}

	return (result);
}
