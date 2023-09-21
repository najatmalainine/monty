#include "monty.h"
/**
 * _swap - swaps the locations of previous stack with the top stack
 * @h: the node to be swapped
 * @line_num: number of the node
 */
void _swap(stack_t **h, unsigned int line_num)
{
	stack_t *temp = NULL;

	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = (*h)->next;
	if (temp->next != NULL)
	{
		(*h)->next = temp->next;
		(*h)->next->prev = *h;
	}
	else
	{
		temp->prev->prev = temp;
		temp->prev->next = NULL;
	}
	temp->prev = NULL;
	temp->next = *h;
	(*h) = temp;
}
