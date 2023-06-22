#include "monty.h"

void do_nothing(void);

operation_t _global_operation;

/**
 * main - Entry point into monty program.
 *
 * @argc: The number of command line arguments
 * @argv: The ccommand line arguments
 *
 * Return: EXIT_SUCCESS on a successful operation
 * otherwise EXIT_FAILURE.
 *
 **/
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
	{
		_error(&exit_code, 0, "USAGE: monty file");
	}
	else
	{
		file = _openfile(argv[1], &exit_code);
		if (file != NULL)
		{
			_processfile(file, &exit_code);
			_closefile(file);
		}
	}
	return (exit_code);
}

/**
 * do_nothing - Do absolutely nothing!
 **/
void do_nothing(void)
{

}
