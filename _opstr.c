#include "monty.h"

/**
 * _opstr - Form a valid string from the stack.
 *
 * @head: The head node in the list.
 * @line_number: The line number read.
 *
 **/
void _opstr(stack_t **head, unsigned int __attribute__((unused))line_number)
{
	stack_t *current = NULL;

	current = *head;
	while (current != NULL)
	{
		if ((current->n == 0) ||
		((current->n < 65 || current->n > 90) &&
		(current->n < 97 || current->n > 122)))
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
