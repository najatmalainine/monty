#include "monty.h"
/**
 * add_ - adding the top two elements in stack
 * @h: top node
 * @line_num: number of node
 */
void add_(stack_t **h, unsigned int line_num)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n += (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}
/**
 * sub_ - subtracting second node from top node
 * @h: top node
 * @line_num: number of line of command
 */
void sub_(stack_t **h, unsigned int line_num)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n -= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}
