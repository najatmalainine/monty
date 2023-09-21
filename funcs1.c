#include "monty.h"


/**
 * stack_add - it adds a node to the stack.
 * @new_n: the pointer to the new node.
 * @line_n: the line number of the opcode.
 */
void stack_add(stack_t **new_n, __attribute__((unused))unsigned int line_n)
{
	stack_t *tmp;

	if (new_n == NULL || *new_n == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_n;
		return;
	}
	tmp = head;
	head = *new_n;
	head->next = tmp;
	tmp->prev = head;
}
/**
 * stck_print - it adds a node to the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_n: line number of  the opcode.
 */
void stck_print(stack_t **stck, unsigned int line_n)
{
	stack_t *tmp;

	(void) line_n;
	if (stck == NULL)
		exit(EXIT_FAILURE);
	tmp = *stck;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
