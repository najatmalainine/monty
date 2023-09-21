#include "monty.h"

/**
 * get_op - the function for selecting correct operation function
 * @tkn1: first bytecode input (opcode)
 * Return: the pointer to correct operation function
 */
void (*get_op(char *tkn1))(stack_t **stack, unsigned int line_num)
{
	instruction_t instruction_s[] = {
		{"pop", _pop},
		{"pall", _pall},
		{"pint", _pint},
		{"swap", _swap},
		{"add", add_},
		{"sub", sub_},
		{"mul", mul_},
		{"div", div_},
		{"mod", mod_},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"nop", _nop},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}};
	int i = 0;

	while (instruction_s[i].f != NULL)
	{
		if (strcmp(tkn1, instruction_s[i].opcode) == 0)
			return (instruction_s[i].f);
		i++;
	}
	return (NULL);
}
