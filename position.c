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
/**
 * _rotl - it rotates so top of stack becomes last one,
 * second becomes first one
 * @h: the node to be rotated
 * @line_num: number of the node
 */
void _rotl(stack_t **h, unsigned int line_num)
{
	stack_t *temp;

	(void)line_num;

	if ((*h)->next != NULL)
	{
		temp = *h;
		while (temp->next != NULL)
			temp = temp->next;
		(*h)->prev = temp;
		temp->next = *h;
		(*h)->next->prev = NULL;
		*h = (*h)->next;
		temp->next->next = NULL;
	}
}
/**
 * _rotr - it rotates so the bottom node of stack becomes first one
 * @h: the node to be rotated
 * @line_num: the number of the node
 */
void _rotr(stack_t **h, unsigned int line_num)
{
	stack_t *temp;

	(void)line_num;

	if ((*h)->next != NULL)
	{
		temp = *h;
		while (temp->next != NULL)
			temp = temp->next;
		(*h)->prev = temp;
		temp->next = *h;
		temp->prev->next = NULL;
		temp->prev = NULL;
		(*h) = (*h)->prev;
	}
}
