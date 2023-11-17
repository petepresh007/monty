#include "monty.h"

/**
 * rotl - s
 * @stk: double linked list
 * @line_number: file line execution
 */
void rotl(stack_t **stk, unsigned int line_number)
{
	stack_t *tm = *stk;
	(void) line_number;

	if (!stk || !*stk || !(*stk)->next)
		return;
	(*stk)->next->prev = NULL;
	while (tm->next)
		tm = tm->next;
	tm->next = *stk;
	(*stk) = (*stk)->next;
	tm->next->next = NULL;
	tm->next->prev = tm;
}

/**
 * rotr - s
 * @stk: double linked list
 * @line_number: file line execution
 */
void rotr(stack_t **stk, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (!stk || !*stk || !(*stk)->next)
		return;

	tmp = *stk;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = *stk;
	tmp->prev->next = NULL;
	tmp->prev = NULL;

	(*stk)->prev = tmp;
	*stk = tmp;
}

/**
 * stack - s
 * @stk: double linked list
 * @line_number: file line execution
 */
void stack(stack_t **stk, unsigned int line_number)
{
	(void) line_number;
	(void) stk;

	variable.MODE = 0;
}

/**
 * queue - s
 * @stk: double linked list
 * @line_number: file line execution
 */
void queue(stack_t **stk, unsigned int line_number)
{
	(void) line_number;
	(void) stk;

	variable.MODE = 1;
}
