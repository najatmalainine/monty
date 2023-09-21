#include "monty.h"
/**
 * _pall - it prints all the nodes in the stack
 * @h: the head of list
 * @line_num: the line number of bytecode
 */
void _pall(stack_t **h, unsigned int line_num)
{
	stack_t *temp = NULL;

	if (!h || !*h)
		return;

	(void)line_num;
	temp = *h;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * _pint - it prints the top node in stack
 * @h: the head of list
 * @line_num: line number of bytecode
 */
void _pint(stack_t **h, unsigned int line_num)
{
	if (!h || !*h)
	{
		printf("L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}
/**
 * _pchar - it prints the top node in stack as an ascii letter
 * @h: the head of list
 * @line_num: bytecode line number
 */
void _pchar(stack_t **h, unsigned int line_num)
{
	if (!h || !*h)
	{
		printf("L%u: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (((*h)->n) >= 0 && ((*h)->n) <= 127)
		printf("%c\n", (*h)->n);
	else
	{
		printf("L%u: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
}
