#include "monty.h"
/**
 * f_pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
void f_pall(stack_s **stack, unsigned int line_number)
{
	stack_s *aux;

	(void)line_number;
	if (stack == NULL)
	{
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	aux = *stack;

	while (aux)
	{
		printf("%i\n", aux->n);
		aux = aux->next;
	}
}

/**
 * f_pint - prints the value at the top of the stack, followed by a new line
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
void f_pint(stack_s **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}

/**
 * f_pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
void f_pchar(stack_s **stack, unsigned int line_number)
{
	stack_s *aux = *stack;

	if (aux == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_stack(aux);
		exit(EXIT_FAILURE);
	}
	if (aux->n < 0 || aux->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(aux);
		exit(EXIT_FAILURE);
	}
	putchar(aux->n);
	putchar('\n');
}

/**
 * f_pstr - prints the string starting at the
 * top of the stack, followed by a new line.
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
void f_pstr(stack_s **stack, unsigned int line_number)
{
	stack_s *aux = *stack;

	(void)line_number;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	while ((aux))
	{
		if (isalpha((int)(aux)->n) == 0 || (aux)->n == 0)
			break;

		printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
}
