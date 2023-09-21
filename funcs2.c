#include "monty.h"

/**
 * _add - it adds the top two elements of the stack.
 * @stck: the top node of the stack.
 * @line_n: the line number of of the opcode.
 */
void _add(stack_t **stck, unsigned int line_n)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		_err_plus(8, line_n, "add");

	(*stck) = (*stck)->next;
	sum = (*stck)->n + (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
/**
 * _sub - it subs the top two elements of the stack.
 * @stck: the top node of the stack.
 * @line_n: the line number of of the opcode.
 */
void _sub(stack_t **stck, unsigned int line_n)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)

		_err_plus(8, line_n, "sub");


	(*stck) = (*stck)->next;
	sum = (*stck)->n - (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
