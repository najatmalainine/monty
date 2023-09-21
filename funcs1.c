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
