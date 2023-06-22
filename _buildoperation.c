#include "monty.h"

/**
 * _buildoperation - Generate an operation with its
 * opcode and operand.
 *
 * @instruction: Opcode and its function.
 * @operand: The operand for the operation.
 * @exit_code: The memory address to the exit code.
 *
 * Return: The generated operation object.
 *
 **/
operation_t _buildoperation(instruction_t instruction, const int operand
                , int *exit_code)
{
	operation_t operation;

	operation.instruction = instruction;
	operation.operand = (operand == NO_OPERAND) ? NO_OPERAND : operand;
	operation.exit_code = exit_code;

	return (operation);
}
