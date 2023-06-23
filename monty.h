#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stddef.h>

#define DELIMITERS " \t\n\r"
#define NO_OPERAND -9876
#define IS_NUMBER 0
#define IS_ALPHA 1
#define IS_COMMENT_YES 1
#define IS_COMMENT_NO 0

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct operation - An instruction with its operand
 * (if any).
 *
 * @instruction: opcode and ites function
 * @operand: operand for the operation
 * @exit_code: the latest exit code for the program
 *
 **/
typedef struct operation
{
	instruction_t instruction;
	int operand;
	int *exit_code;
} operation_t;

void _error(int *exit_code, int argc, const char *err_msg, ...);
FILE *_openfile(const char *pathname, int *exit_code);
void _processfile(FILE *file, int *exit_code);
void _process(char *file_content, int line_number,
		stack_t **head, int *exit_code);
char **_tokenize(char *str, int *exit_code);
int _tokencount(char **tokens);
void _operate(unsigned int line_number, char *opcode, int operand
		, stack_t **head, int *exit_code);
void _opush(stack_t **head, unsigned int line_number);
void _opall(stack_t **head, unsigned int line_number);
void _opop(stack_t **head, unsigned int line_number);
void _oswap(stack_t **head, unsigned int line_number);
void _opint(stack_t **head, unsigned int line_number);
void _oadd(stack_t **head, unsigned int line_number);
void _osub(stack_t **head, unsigned int line_number);
void _odiv(stack_t **head, unsigned int line_number);
void _omul(stack_t **head, unsigned int line_number);
void _omod(stack_t **head, unsigned int line_number);
void _opchar(stack_t **head, unsigned int line_number);
void _opstr(stack_t **head, unsigned int line_number);
void _orotl(stack_t **head, unsigned int line_number);
void _orotr(stack_t **head, unsigned int line_number);
char *_itoa(int number, int *exit_code);
char *_strrev(char *str, int *exit_code);
int _strlen(char *str);
void _closefile(FILE *file);
operation_t _buildoperation(instruction_t, const int operand,
		int *exit_code);
int _stackoperation(operation_t instruction,
unsigned int line_number, stack_t **head);
void free_stack(stack_t **head);
int _isnumber(char *str);
int _iscomment(char *str);

extern operation_t _global_operation;

#endif
