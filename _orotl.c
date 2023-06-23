#include "monty.h"

/**
 * _orotl - Rotate the stack to the top element.
 *
 * @head: The head node in the list.
 * @line_number: The line number read.
 *
 */
void _orotl(stack_t **head, unsigned int __attribute__((unused))line_number)
{
	stack_t *current = NULL;
	int tmp = 0;

	if ((*head) == NULL)
	{
		return;
	}
	current = *head;
	tmp = current->n;
	while (current->next != NULL)
	{
		current = current->next;
		current->prev->n = current->n;
		current->n = tmp;
	}
}
