#include "monty.h"
/**
 * swap - Delete top of list
 * @stk: Double linked list
 * @line_number: File line execution
 */
void swap(stack_t **stk, unsigned int line_number)
{
	int tmp;

	if (!*stk || !(*stk)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = (*stk)->n;
	(*stk)->n = (*stk)->next->n;
	(*stk)->next->n = tmp;
}

/**
 * add - add the top two elements of the stack
 * @stk: Double linked list
 * @line_number: File line execution
 */

void add(stack_t **stk, unsigned int line_number)
{
	if (!*stk || !(*stk)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stk)->next->n = (*stk)->next->n + (*stk)->n;
	pop(stk, line_number);
}

/**
 * sub - substract the top two elements of the stack
 * @stk: Double linked list
 * @line_number: Line counter
 */

void sub(stack_t **stk, unsigned int line_number)
{
	if (!*stk || !(*stk)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stk)->next->n = (*stk)->next->n - (*stk)->n;
	pop(stk, line_number);
}

/**
 * divi - divide the top two elements of the stack
 * @stk: Double linked list
 * @line_number: File line counter
 */
void divi(stack_t **stk, unsigned int line_number)
{
	if (!*stk || !(*stk)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stk)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stk)->next->n = (*stk)->next->n / (*stk)->n;
	pop(stk, line_number);
}
