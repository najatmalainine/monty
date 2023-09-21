#include "monty.h"

/**
 * _isnumber - it iterates each character of string to check if isdigit
 * @n: int
 * Return: 0 if is number, else -1 if not
 */
int _isnumber(const char *n)
{
	int i = 0;

	if (*n == '-')
		i = 1;
	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
			return (-1);
	}
	return (0);
}
/**
 * _push - it adds a node to the start of double linked list
 * @h: the head of linked list (node at the bottom of stack)
 * @line_num: line number of bytecode
 * @n: int
 */
void _push(stack_t **h, unsigned int line_num, const char *n)
{
	if (!h)
		return;
	if (_isnumber(n) == -1)
	{
		printf("L%u: usage: push integer\n", line_num);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_end_node(h, atoi(n)) == -1)
		{
			free_dlist(h);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * _pop - it removes the node at the front of double linked list
 * @h: the head of linked list (node at the bottom of stack)
 * @line_num: bytecode line number
 */
void _pop(stack_t **h, unsigned int line_num)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_num);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	else
		delete_end_node(h);
}
