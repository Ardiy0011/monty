#include "monty.h"

/**
 * _opop - Remove the top element.
 *
 * @head: The head node in the list.
 * @line_number: The line number read.
 *
 **/
void _opop(stack_t **head, unsigned int __attribute__((unused))line_number)
{
	char *itoa = NULL;
	operation_t operation;
	stack_t *current = NULL;

	if (*head == NULL)
	{
		operation = _global_operation;
		itoa = _itoa(line_number, operation.exit_code);
		if (itoa != NULL)
		{
			_error(operation.exit_code, 2, "L", itoa,
			": can't pop an empty stack");
			free(itoa);
			*_global_operation.exit_code = EXIT_FAILURE;
		}
		return;
	}
	current = *head;
	*head = (*head)->next;
	if ((*head) != NULL)
	{
		(*head)->prev = NULL;
	}
	free(current);
}
