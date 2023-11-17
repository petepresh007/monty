#include "monty.h"

/**
 * pall - double linked list
 * @stk: double linked list
 * @line_number: line exec
 */
void pall(stack_t **stk, unsigned int line_number)
{
	stack_t *tmp = *stk;
	(void) line-number;

	if (!tmp)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * push - insert a new value
 * @stk: double linked list
 * @line_number: file line exec
 */
void push(stack_t **stk, unsigned int line_number)
{
	stack_t *tmp = NULL, *tm = *stk;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (line_number[num] != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->n = atoi(num);
	if (variable.MODE == 0 || !*stk)
	{
		tmp->next = *stk;
		tmp->prev = NULL;
		if (*stk)
			(*stk)->prev = tmp;
		*stk = tmp;
	}
	else
	{
		while (tm->next)
			tm = tm->next;
		tm->next = tmp;
		tmp->prev = tm;
		tmp->next = NULL;
	}
}

/**
 * pint - print last node
 * @stk: doube linked list
 * @line_number: file line exec
 */
void pint(stack_t **stk, unsigned int line_number)
{
	if (!*stk)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stk)->n);
}

/**
 * pop - delete top of list
 * @stk: double linked list
 * @line_number: file line exec
 */
void pop(stack_t **stk, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stk)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	tmp = *stk;
	*stk = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
}
