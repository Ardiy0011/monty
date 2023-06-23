#include "monty.h"

/**
 * _omod - this provides the remainder of the division btwn
 *          the 2nd top element of the stack the top element
 *
 * @head: The head node in the list.
 * @line_number: particular line read at given time by getline
 */
void _omod(stack_t **head, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;
	char *itoa = NULL, *msg = NULL;
	operation_t operation;
	int result = 0;

	if (((*head) == NULL || (*head)->next == NULL) ||
	((*head) != NULL && (*head)->n == 0))
	{
		msg = "division by zero";
		if ((*head) == NULL || (*head)->next == NULL)
		{
			msg = "can't mod, stack too short";
		}
		operation = _global_operation;
		itoa = _itoa(line_number, operation.exit_code);
		_error(operation.exit_code, 3, "L", itoa,
		": ", msg);
		free(itoa);
		*_global_operation.exit_code = EXIT_FAILURE;
		return;
	}
	first = *head;
	second = (*head)->next;
	result = second->n % first->n;
	second->n = result;
	*head = second;
	(*head)->prev = NULL;
	free(first);
}
