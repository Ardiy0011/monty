#include "monty.h"

/**
 * _openfile - Open the given file.
 *
 * @pathname: The full path to the file to open.
 * @exit_code: The memory address to the exit code.
 *
 * Return: The memory address to the open file
 *
 **/
FILE *_openfile(const char *pathname, int *exit_code)
{
	FILE *file = NULL;

	file = fopen(pathname, "r");
	if (file == NULL)
	{
		_error(exit_code, 1, "Error: Can't open file ", pathname);
	}
	return (file);
}
