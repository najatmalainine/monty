#include "monty.h"

/**
 * _mul - it multiplies the top two elements of the stack.
 * @stck: the top node of the stack.
 * @line_number: the line number of of the opcode.
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
