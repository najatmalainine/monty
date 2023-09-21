#include "monty.h"

/**
 * line_parse - it separates each line into tokens to determine
 * which function to call
 * @buf: the line from the file
 * @line_num: line number
 * @format:  the storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int line_parse(char *buf, int line_num, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buf == NULL)
		_err(4);

	opcode = strtok(buf, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	fun_find(opcode, value, line_num, format);
	return (format);
}
/**
 * file_read - it reads a file
 * @fd: the pointer to file descriptor
 * Return: nothing
 */

void file_read(FILE *fd)
{
	int line_num, format = 0;
	char *buf = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buf, &len, fd) != -1; line_num++)
	{
		format = line_parse(buf, line_num, format);
	}
	free(buf);
}
/**
 * file_open - it opens a file
 * @file_n: the file name
 * Return: void
 */

void file_open(char *file_n)
{
	FILE *fd = fopen(file_n, "r");

	if (file_n == NULL || fd == NULL)
		_err(2, file_n);

	file_read(fd);
	fclose(fd);
}
/**
 * fun_find - it finds the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void fun_find(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", stack_add},
		{"pall", stck_print},
		{"pint", top_print},
		{"pop", top_pop},
		{"nop", nop},
		{"swap", n_swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", char_print},
		{"pstr", str_print},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			func_call(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		_err(3, ln, opcode);
}
/**
 * func_call - it calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @opc: string representing the opcode.
 * @val: string representing a numeric value.
 * @line_n: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void func_call(op_f func, char *opc, char *val, int line_n, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opc, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			_err(5, line_n);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				_err(5, line_n);
		}
		node = n_create(atoi(val) * flag);
		if (format == 0)
			func(&node, line_n);
		if (format == 1)
			queue_add(&node, line_n);
	}
	else
		func(&head, line_n);
}
