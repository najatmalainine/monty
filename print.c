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
