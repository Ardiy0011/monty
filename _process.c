#include "monty.h"

/**
 * _process - Process a line read from the file.
 *
 * @file_content: The line read from the line.
 * @line_number: The line number read.
 * @head: The head node in the list
 * @exit_code: The memory address to the exit code.
 *
 **/
void _process(char *file_content, int line_number,
	stack_t **head, int *exit_code)
{
	char **tokens = NULL;
	char *opcode = NULL;
	int token_count = 0, operand = NO_OPERAND;

	if (_iscomment(file_content) == IS_COMMENT_YES)
	{
		return;
	}
	tokens = _tokenize(file_content, exit_code);
	if (tokens == NULL)
	{
		return;
	}
	token_count = _tokencount(tokens);
	if (token_count == 0)
	{
		free(tokens);
		return;
	}
	opcode = tokens[0];
	if (token_count == 2)
	{
		if (_isnumber(tokens[1]) == IS_NUMBER)
		{
			operand = atoi(tokens[1]);
		}
		else
		{
			operand = NO_OPERAND;
		}
	}
	_operate(line_number, opcode, operand, head, exit_code);
	free(tokens);
}
