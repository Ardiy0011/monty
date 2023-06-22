#include "monty.h"

/**
 * _opush - Push an item to the top of the list.
 *
 * @head: The head node in the list.
 * @line_number: The line number read.
 *
 **/
void _opush(stack_t **head, unsigned int __attribute__((unused))line_number)
{
	stack_t *node = NULL;
	operation_t operation;
	char *itoa = NULL;

	operation = _global_operation;
	if (operation.operand == NO_OPERAND)
	{
		itoa = _itoa(line_number, operation.exit_code);
		if (itoa != NULL)
		{
			_error(operation.exit_code, 4, "L", itoa, ": usage: "
				, operation.instruction.opcode, " integer");
			free(itoa);
			*_global_operation.exit_code = EXIT_FAILURE;
		}
		return;
	}
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		_error(operation.exit_code, 0, "Error: malloc failed");
		*operation.exit_code = EXIT_FAILURE;
		return;
	}
	node->n = operation.operand;
	node->prev = NULL;
	node->next = *head;
	if ((*head) != NULL)
	{
		(*head)->prev = node;
	}
	(*head) = node;
}
