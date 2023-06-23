#include "monty.h"

/**
 * _orotr - Rotate the stack to the bottom element.
 *
 * @head: The head node in the list.
 * @line_number: The line number read.
 *
 */
void _orotr(stack_t **head, unsigned int __attribute__((unused))line_number)
{
	stack_t *current = NULL;
	int tmp = 0;

	if ((*head) == NULL)
	{
		return;
	}
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	tmp = current->n;
	while (current->prev != NULL)
	{
		current = current->prev;
		current->next->n = current->n;
		current->n = tmp;
	}
}
