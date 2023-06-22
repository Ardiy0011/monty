#include "monty.h"

/**
 * _oswap - Swap the opcode of the top two elements.
 *
 * @head: The head node in the list.
 * @line_number: The line number read.
 *
 **/
void _oswap(stack_t **head, unsigned int __attribute__((unused))line_number)
{
	int first_value = 0;
	char *itoa = NULL;
	operation_t operation;

	if ((*head) != NULL && (*head)->next != NULL)
	{
		first_value = (*head)->n;
		(*head)->n = (*head)->next->n;
		(*head)->next->n = first_value;
		return;
	}
	operation = _global_operation;
	itoa = _itoa(line_number, operation.exit_code);
	if (itoa != NULL)
	{
		_error(operation.exit_code, 2, "L", itoa,
		": can't swap, stack too short");
		free(itoa);
		*_global_operation.exit_code = EXIT_FAILURE;
	}
}
