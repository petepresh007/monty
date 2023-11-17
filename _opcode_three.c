#include "monty.h"
/**
 * isascii - checks
 * @c: params
 * Return: isascii
 */
int isascii(int c);

/**
 * mul - sub
 * @stk: Double linked list
 * @line_number: File line execution
 */

void mul(stack_t **stk, unsigned int line_number)
{
	if (!*stk || !(*stk)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stk)->next->n = (*stk)->next->n * (*stk)->n;
	pop(stk, line_number);
}

/**
 * mod - sub
 * @stk: Double linked list
 * @line_number: File line execution
 */
void mod(stack_t **stk, unsigned int line_number)
{
	if (!*stk || !(*stk)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stk)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stk)->next->n = (*stk)->next->n % (*stk)->n;
	pop(stk, line_number);
}

/**
 * pchar - sub
 * @stk: Double linked
 * @line_number: file line execution
 */
void pchar(stack_t **stk, unsigned int line_number)
{
	if (!stk || !*stk)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (isascii((*stk)->n))
	{
		printf("%c\n", (*stk)->n);
		return;
	}
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * pstr - s
 * @stk: Double linked list
 * @line_number: File line execution
 */
void pstr(stack_t **stk, unsigned int line_number)
{
	stack_t *tmp = *stk;
	(void) line_number;

	if (!stk || !*stk)
	{
		putchar('\n');
		return;
	}
	while (tmp)
	{
		if (tmp->n == 0)
			break;
		if (!isascii((tmp)->n))
			break;
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
