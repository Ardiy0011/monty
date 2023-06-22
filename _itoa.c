#include "monty.h"

/**
 * _itoa - Convert a number to its string
 * representation.
 *
 * @number: The given number.
 * @exit_code: The memory address to the exit code.
 *
 * Return: The string representation for the given
 * string
 *
 **/
char *_itoa(int number, int *exit_code)
{
	int num_dup = 0, digits = 0, tmp = 0, index = 0;
	char *str = NULL;

	num_dup = number;
	while (num_dup != 0)
	{
		num_dup /= 10;
		digits++;
	}
	str = malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
	{
		_error(exit_code, 0, "Error: malloc failed");
		return (NULL);
	}
	while (number != 0)
	{
		tmp = number % 10;
		str[index] = tmp + '0';
		number /= 10;
		index++;
	}
	str[index] = '\0';

	return (_strrev(str, exit_code));
}
