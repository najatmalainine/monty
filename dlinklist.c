#include "monty.h"
/**
 * add_end_node - adding node to front of doubly linked list
 * @h: head of list
 * @n: the data
 * Return: 0 if success, -1 if failed
 */
int add_end_node(stack_t **h, int n)
{
	stack_t *new_node;

	if (!h)
		return (-1);

	new_node = malloc(sizeof(struct stack_s));
	if (!new_node)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	new_node->n = n;


	if (*h == NULL)
	{
		*h = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		new_node->next = *h;
		(*h)->prev = new_node;
		*h = new_node;
	}
	return (0);
}
/**
 * delete_end_node - deleting the node at end of doubly linked list
 * @h: head of doubly linked list
 */
void delete_end_node(stack_t **h)
{
	stack_t *del = NULL;


	del = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(del);
	}
	else
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(del);
	}
}
/**
 * free_dlist - it frees a doubly linked list with only int data, no strings
 * @h: head of list
 */
void free_dlist(stack_t **h)
{

	if (!h)
		return;

	while (*h && (*h)->next)
	{
		*h = (*h)->next;
		free((*h)->prev);
	}
	free(*h);
}
