#include "monty.h"
/**
 * search_function - searches token in options of opcode.
 * @head: head of double linked lisd
 * @line_n: line of code of file bytecode
 * @token: token of input file
 * Return: 0 on success, 1 on error
 **/
int search_function(char *token, unsigned int line_n, stack_s **head)
{
	instruction_t options[] = {
		{"pall", f_pall}, {"push", f_push}, {"pint", f_pint},
		{"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
		{"sub", f_sub}, {"div", f_div}, {"mul", f_mul},
		{"mod", f_mod}, {"pchar", f_pchar}, {"pstr", f_pstr},
		{"nop", f_nop}, {"rotl", f_rotl}, {"rotr", f_rotr}, {NULL, NULL}
	};
	int i = 0;

	while (options[i].opcode != NULL)
	{
		if (strcmp(options[i].opcode, token) == 0)
		{
			options[i].f(head, line_n);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_n, token);
	free_stack(*head);
	exit(EXIT_FAILURE);
}

/**
 * f_push - pushes an element to the stack.
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
void f_push(stack_s **stack, unsigned int line_number)
{
	stack_s *new = NULL;

	(void) line_number;
	if (!stack)
	{
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_s));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new->n = number;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * f_pop - removes the top element of the stack.
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
void f_pop(stack_s **stack, unsigned int line_number)
{
	stack_s *aux;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	*stack = (*stack)->next;
	free(aux);
}
