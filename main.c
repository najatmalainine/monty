#include "monty.h"

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	int fd, is_p = 0;
	unsigned int line = 1;
	ssize_t n_read;
	char *buf, *tkn;
	stack_t *h = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buf = malloc(sizeof(char) * 10000);
	if (!buf)
		return (0);
	n_read = read(fd, buf, 10000);
	if (n_read == -1)
	{
		free(buf);
		close(fd);
		exit(EXIT_FAILURE);
	}
	tkn = strtok(buf, "\n\t\a\r ;:");
	while (tkn != NULL)
	{
		if (is_p == 1)
		{
			_push(&h, line, tkn);
			is_p = 0;
			tkn = strtok(NULL, "\n\t\a\r ;:");
			line++;
			continue;
		}
		else if (strcmp(tkn, "push") == 0)
		{
			is_p = 1;
			tkn = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (get_op(tkn) != 0)
			{
				get_op(tkn)(&h, line);
			}
			else
			{
				free_dlist(&h);
				printf("L%d: unknown instruction %s\n", line, tkn);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		tkn = strtok(NULL, "\n\t\a\r ;:");
	}
	free_dlist(&h);
	free(buf);
	close(fd);
	return (0);
}
