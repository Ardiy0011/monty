#include "monty.h"

/**
 * _processfile - Process the contents in the given
 * file.
 *
 * @file: The memory address to the file to close.
 * @exit_code: The memory address to the exit code.
 *
 **/
void _processfile(FILE *file, int *exit_code)
{
	char *file_content = NULL;
	size_t buff_size = 0;
	int line_number = 0;
	stack_t *head = NULL;

	while (getline(&file_content, &buff_size, file) != -1)
	{
		line_number++;
		_process(file_content, line_number, &head, exit_code);
		if (*exit_code == EXIT_FAILURE)
		{
			free(file_content);
			free_stack(&head);
			return;
		}
	}
	free(file_content);
	free_stack(&head);
}
