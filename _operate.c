#include "monty.h"

/**
 * _operate - Find the appropriate operation to
 * perform.
 *
 * @line_number: The line number read.
 * @opcode: The operation to perform.
 * @operand: The data value for the operation.
 * @head: The head node in the list
 * @exit_code: The memory address to the exit code.
 *
 **/
void _operate(unsigned int line_number, char *opcode,
	int operand, stack_t **head, int *exit_code)
{
	int index = 0;
	char *itoa = NULL;
	instruction_t insts[] = {
		{"push", _opush}
		, {"pall", _opall}
		, {"pint", _opint}
		, {"pop", _opop}
		, {"swap", _oswap}
		, {"add", _oadd}
		, {"sub", _osub}
		, {"div", _odiv}
		, {"mul", _omul}
		, {"mod", _omod}
		, {"#", _comment}
		, {"nop", NULL}
		, {NULL, NULL}
	};
	instruction_t inst;
	operation_t operation;

	while (insts[index].opcode != NULL &&
			(strcmp(insts[index].opcode, opcode) != 0))
	{
		index++;
	}
	inst = insts[index];
	if (inst.opcode == NULL)
	{
		itoa = _itoa(line_number, exit_code);
		if (itoa != NULL)
		{
			_error(exit_code, 3, "L", itoa,
					": unknown instruction ", opcode);
			free(itoa);
		}
		return;
	}
	operation = _buildoperation(inst, operand, exit_code);
	*exit_code = _stackoperation(operation, line_number, head);
}
