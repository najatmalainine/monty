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
