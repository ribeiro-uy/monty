#include "monty.h"

/**
 * f_rotl - rotates the stack to the top.
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
void f_rotl(stack_s **stack, unsigned int line_number)
{
	stack_s *aux, *new;
	unsigned int temp;
	int stack_len = 0;

	(void)line_number;
	stack_len = list_len(stack);
	if (*stack != NULL && stack_len >= 2)
	{
		new = malloc(sizeof(stack_s));
		if (!new)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		aux = *stack;
		temp = aux->n;
		*stack = aux->next;
		free(aux);
		aux = *stack;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
		new->n = temp;
		new->prev = aux;
		new->next = NULL;
	}
}

/**
 * f_rotr - rotates the stack to the bottom
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
void f_rotr(stack_s **stack, unsigned int line_number)
{
	stack_s *aux = NULL, *new = NULL;
	int stack_len = 0;

	(void)line_number;
	stack_len = list_len(stack);
	if (*stack != NULL && stack_len >= 2)
	{
		new = malloc(sizeof(stack_s));
		if (!new)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		new->prev = NULL;
		aux = *stack;
		while (aux->next->next)
			aux = aux->next;
		new->n = aux->next->n;
		free(aux->next);
		aux->next = NULL;
		aux = *stack;
		new->next = aux;
		*stack = new;
	}
}
