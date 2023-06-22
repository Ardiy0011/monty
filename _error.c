#include "monty.h"

/**
 * _error - Display an error message to the standard error
 * stream.
 *
 * @exit_code: The memory address to the exit code.
 * @argc: The number of arguments given to this function.
 * @err_msg: The first message to be displayed
 *
 **/
void _error(int *exit_code, int argc, const char *err_msg, ...)
{
	char *msg = NULL;
	va_list args;
	int count = 0;

	va_start(args, err_msg);

	fprintf(stderr, "%s", err_msg);
	while (count < argc)
	{
		msg = va_arg(args, char *);
		fprintf(stderr, "%s", msg);
		count++;
	}
	fprintf(stderr, "\n");
	*exit_code = EXIT_FAILURE;
}
