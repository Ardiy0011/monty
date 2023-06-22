#include "monty.h"

/**
 * _odiv - this divides the 2nd to top value to top
 *
 * @head: The head node in the list.
 * @line_number: particular line read at given time by getline
 */
void _odiv(stack_t **head, unsigned int line_number)
{
    stack_t *tmp = NULL;
    char *itoa = NULL;
    operation_t operation;
    int result = 0;

    if ((*head) != NULL && (*head)->next != NULL)
    {
        tmp = *head;
        result = (*head)->next->n;
        
        if (result == 0)
        {
            operation = _global_operation;
            itoa = _itoa(line_number, operation.exit_code);
            _error(operation.exit_code, 2, "L", itoa, ": division by zero");
            free(itoa);
            *_global_operation.exit_code = EXIT_FAILURE;
            return;
        }

        result = (*head)->n / result;
        (*head) = (*head)->next;
        (*head)->n = result;
        (*head)->prev = NULL;
        free(tmp);
        return;
    }

    operation = _global_operation;
    itoa = _itoa(line_number, operation.exit_code);
    _error(operation.exit_code, 2, "L", itoa, ": can't div, stack too short");
    free(itoa);
    *_global_operation.exit_code = EXIT_FAILURE;
}
