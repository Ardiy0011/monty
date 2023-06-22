#include "monty.h"

/**
 * _oadd - Add the top two elements of the list.
 *
 * @head: The head node in the list.
 * @line_number: The line number read.
 *
 **/
void _oadd(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL;
	char *itoa = NULL;
	operation_t operation;
	int result = 0;

	if ((*head) != NULL && (*head)->next != NULL)
	{
		tmp = *head;
		result = (*head)->n;
		result += (*head)->next->n;
		(*head) = (*head)->next;
		(*head)->n = result;
		(*head)->prev = NULL;
		free(tmp);
		return;
	}
	operation = _global_operation;
	itoa = _itoa(line_number, operation.exit_code);
	if (itoa != NULL)
	{
		_error(operation.exit_code, 2, "L", itoa,
		": can't add, stack too short");
		free(itoa);
		*_global_operation.exit_code = EXIT_FAILURE;
	}
}
