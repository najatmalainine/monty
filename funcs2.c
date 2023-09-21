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
/**
 * _div - it divides the top two elements of the stack.
 * @stck: the top node of the stack.
 * @line_n: the line number of of the opcode.
 */
void _div(stack_t **stck, unsigned int line_n)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		_err_plus(8, line_n, "div");

	if ((*stck)->n == 0)
		_err_plus(9, line_n);
	(*stck) = (*stck)->next;
	sum = (*stck)->n / (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
/**
 * nop - Does nothing.
 * @stck: thetop node of the stack.
 * @line_n: the line number of of the opcode.
 */
void nop(stack_t **stck, unsigned int line_n)
{
	(void)stck;
	(void)line_n;
}
/**
 * n_swap - it swaps the top two elements of the stack.
 * @stck: the top node of the stack.
 * @line_n: the line number of of the opcode.
 */
void n_swap(stack_t **stck, unsigned int line_n)
{
	stack_t *temp;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		_err_plus(8, line_n, "swap");
	temp = (*stck)->next;
	(*stck)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stck;
	temp->next = *stck;
	(*stck)->prev = temp;
	temp->prev = NULL;
	*stck = temp;
}
