#include "monty.h"
/**
 * free_stack - free all elements of stack.
 * @head: head of double linked lisd
 **/
void free_stack(stack_s *head)
{
	stack_s *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}
