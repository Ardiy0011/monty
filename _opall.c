#include "monty.h"

/**
 * _opall - Displays items in a given list.
 *
 * @head: The head node in the list.
 * @line_number: The line number read.
 *
 **/
void _opall(stack_t **head, unsigned int __attribute__((unused))line_number)
{
	stack_t *current = NULL;

	if (*head == NULL)
	{
		return;
	}
	current = *head;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

}
