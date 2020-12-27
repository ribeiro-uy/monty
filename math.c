#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
void f_add(stack_s **stack, unsigned int line_number)
{
	stack_s *temp_node;
	size_t len = 0;
	unsigned int temp;

	len = list_len(stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n + (*stack)->next->n;
	temp_node = *stack;
	*stack = (*stack)->next;
	(*stack)->n = temp;
	free(temp_node);
}
/**
 * f_sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
void f_sub(stack_s **stack, unsigned int line_number)
{
	stack_s *temp_node;
	size_t len = 0;
	unsigned int temp;

	len = list_len(stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n - (*stack)->n;
	temp_node = *stack;
	*stack = (*stack)->next;
	(*stack)->n = temp;
	free(temp_node);
}
/**
 * f_mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
void f_mul(stack_s **stack, unsigned int line_number)
{
	stack_s *temp_node;
	size_t len = 0;
	unsigned int temp;

	len = list_len(stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n * (*stack)->n;
	temp_node = *stack;
	*stack = (*stack)->next;
	(*stack)->n = temp;
	free(temp_node);
}
/**
 * f_div - divides the second top element of the
 * stack by the top element of the stack.
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
void f_div(stack_s **stack, unsigned int line_number)
{
	stack_s *temp_node;
	size_t len = 0;
	unsigned int temp;

	len = list_len(stack);

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n != 0)
		temp = (*stack)->next->n / (*stack)->n;
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp_node = *stack;
	*stack = (*stack)->next;
	(*stack)->n = temp;
	free(temp_node);
}
/**
 * f_mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stack: head of double linked lisd
 * @line_number: line of code of file bytecode
 **/
void f_mod(stack_s **stack, unsigned int line_number)
{
	stack_s *temp_node;
	size_t len = 0;
	unsigned int temp;

	len = list_len(stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n != 0)
		temp = (*stack)->next->n % (*stack)->n;
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp_node = *stack;
	*stack = (*stack)->next;
	(*stack)->n = temp;
	free(temp_node);
}
