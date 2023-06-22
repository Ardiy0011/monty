#include "monty.h"

/**
 * free_stack - Free a list.
 *
 * @head: The head node in the list
 *
 **/
void free_stack(stack_t **head)
{
	stack_t *current = NULL, *previous = NULL;

	current = *head;
	while (current != NULL)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
}
