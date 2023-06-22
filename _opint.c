#include "monty.h"

/**
 * _opint - Print the value of the top node in the
 * list.
 *
 * @head: The head node in the list.
 * @line_number: The line number read.
 *
 **/
void _opint(stack_t **head, unsigned int __attribute__((unused))line_number)
{
	char *itoa = NULL;
	operation_t operation;

	if (*head == NULL)
	{
		operation = _global_operation;
		itoa = _itoa(line_number, operation.exit_code);
		if (itoa != NULL)
		{
			_error(operation.exit_code, 2, "L", itoa,
			": can't pint, stack empty");
			free(itoa);
			*_global_operation.exit_code = EXIT_FAILURE;
		}
		return;
	}
	printf("%d\n", (*head)->n);
}
