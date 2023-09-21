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