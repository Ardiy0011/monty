#include "monty.h"

/**
 * _stackoperation - Invoke the appropriate function
 * to handle stack manipulation.
 *
 * @operation: Opcode and its function.
 * @line_number: The line number read.
 * @head: The head node in the list
 *
 * Return: The exit code for the latest stack operation.
 *
 **/
int _stackoperation(operation_t operation, unsigned int line_number
	, stack_t **head)
{
	_global_operation.instruction = operation.instruction;
	_global_operation.operand = operation.operand;
	_global_operation.exit_code = operation.exit_code;
	if (_global_operation.instruction.f != NULL)
	{
		_global_operation.instruction.f(head, line_number);
	}

	return (*_global_operation.exit_code);
}
