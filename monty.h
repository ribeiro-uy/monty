#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

extern int number;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_s;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_s **stack, unsigned int line_number);
} instruction_t;

int search_function(char *, unsigned int, stack_s **);
void f_push(stack_s **stack, unsigned int line_number);
void f_pall(stack_s **stack, unsigned int line_number);
void check_token(char *token, unsigned int line_n);
void f_pint(stack_s **stack, unsigned int line_number);
void f_pop(stack_s **stack, unsigned int line_number);
void f_nop(stack_s **stack, unsigned int line_number);
void f_swap(stack_s **stack, unsigned int line_number);
size_t list_len(stack_s **h);
void f_add(stack_s **stack, unsigned int line_number);
void f_sub(stack_s **stack, unsigned int line_number);
void f_mul(stack_s **stack, unsigned int line_number);
void f_div(stack_s **stack, unsigned int line_number);
void f_mod(stack_s **stack, unsigned int line_number);
void f_pchar(stack_s **stack, unsigned int line_number);
void f_pstr(stack_s **stack, unsigned int line_number);
void free_stack(stack_s *head);
void f_rotl(stack_s **stack, unsigned int line_number);
void f_rotr(stack_s **stack, unsigned int line_number);
void tokenize(char *line, stack_s **stack, unsigned int line_n);
void func_main(char *);
#endif

