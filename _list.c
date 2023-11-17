#include "monty.h"

/**
 * free_list - Frees the stack_t doubly list
 * @stk: A double pointer to the head of the list
*/

void free_list(stack_t **stk)
{
	stack_t *temp = *stk;

	if (!*stk)
		return;

	while (*stk)
	{
		*stk = (*stk)->next;
		free(temp);
		temp = *stk;
	}
}
