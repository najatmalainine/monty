#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_f)(stack_t **, unsigned int);

void _add(stack_t **, unsigned int);
void _sub(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void _mul(stack_t **, unsigned int);
void _mod(stack_t **, unsigned int);

void file_open(char *file_name);
int line_parse(char *buffer, int line_number, int format);
void file_read(FILE *);
int char_len(FILE *);
void fun_find(char *, char *, int, int);

stack_t *n_create(int n);
void n_free(void);
void stck_print(stack_t **, unsigned int);
void stack_add(stack_t **, unsigned int);
void queue_add(stack_t **, unsigned int);

void func_call(op_f, char *, char *, int, int);

void top_print(stack_t **, unsigned int);
void top_pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void n_swap(stack_t **, unsigned int);

void char_print(stack_t **, unsigned int);
void str_print(stack_t **, unsigned int);
void _rotl(stack_t **, unsigned int);
void _rotr(stack_t **, unsigned int);

void _err(int error_code, ...);
void _err_plus(int error_code, ...);
void err_str(int error_code, ...);

#endif
