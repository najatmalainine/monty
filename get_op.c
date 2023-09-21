#include "monty.h"

/**
 * _mul - it multiplies the top two elements of the stack.
 * @stck: the top node of the stack.
 * @line_n: the line number of of the opcode.
 */
void _mul(stack_t **stck, unsigned int line_n)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		_err_plus(8, line_n, "mul");

	(*stck) = (*stck)->next;
	sum = (*stck)->n * (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
/**
 * _mod - returns the modulus of the top two elements of the stack.
 * @stck: the top node of the stack.
 * @line_n: the line number of of the opcode.
 */
void _mod(stack_t **stck, unsigned int line_n)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)

		_err_plus(8, line_n, "mod");


	if ((*stck)->n == 0)
		_err_plus(9, line_n);
	(*stck) = (*stck)->next;
	sum = (*stck)->n % (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
