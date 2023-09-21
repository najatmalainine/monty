#include "monty.h"

/**
 * char_print - it prints the Ascii value.
 * @stck: the top node of the stack.
 * @line_n: the line number of of the opcode.
 */
void char_print(stack_t **stck, unsigned int line_n)
{
	int ascii;

	if (stck == NULL || *stck == NULL)
		err_str(11, line_n);

	ascii = (*stck)->n;
	if (ascii < 0 || ascii > 127)
		err_str(10, line_n);
	printf("%c\n", ascii);
}
/**
 * str_print - it prints a string.
 * @stck: the top node of the stack.
 * @line_n: Interger representing the line number of of the opcode.
 */
void str_print(stack_t **stck, __attribute__((unused))unsigned int line_n)
{
	int ascii;
	stack_t *temp;

	if (stck == NULL || *stck == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stck;
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}
