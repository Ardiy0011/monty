#include "monty.h"

/**
 * _opchar - Print the ASCII representation for value
 * of the first item in the list.
 *
 * @head: The head node in the list.
 * @line_number: The line number read.
 *
 **/
void _opchar(stack_t **head, unsigned int line_number)
{
	stack_t *current = NULL;
	operation_t operation;
	char *itoa = NULL, *msg = NULL;

	if ((*head) == NULL || ((*head)->n < 0 || (*head)->n > 127))
	{
		operation = _global_operation;
		itoa = _itoa(line_number, operation.exit_code);
		msg = "can't pchar, value out of range";
		if ((*head) == NULL)
		{
			msg = "can't pchar, stack empty";
		}
		if (itoa != NULL)
		{
			_error(operation.exit_code, 3, "L", itoa, ": ", msg);
			free(itoa);
			*_global_operation.exit_code = EXIT_FAILURE;
		}
		return;
	}
	current = *head;
	printf("%c\n", current->n);
}
