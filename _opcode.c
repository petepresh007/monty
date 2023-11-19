#include "monty.h"

/**
 * the_pall - prints all values on the stack
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
 * Return: nothing
*/

void the_pall(stack_t **stk, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (!*stk)
		return;

	temp = *stk;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * nop - Blank
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void nop(stack_t **stk, unsigned int line_number)
{
	(void)*stk;
	(void)line_number;
}


/**
 * just_add - Adds elements to the stack
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void just_add(stack_t **stk, unsigned int line_number)
{
	stack_t *temp = *stk;
	size_t len = 0;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	temp = *stk;
	*stk = (*stk)->next;
	(*stk)->n += temp->n;
	free(temp);
}


/**
 * the_pop - Removes the top element of the stack
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void the_pop(stack_t **stk, unsigned int line_number)
{
	stack_t *temp = *stk;

	if (!*stk)
	{
		fprintf(stderr, "L%d: can't pop, stack empty\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	*stk = (*stk)->next;
	free(temp);
}


/**
 * the_swap - Swaps the top two elements of the stack
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void the_swap(stack_t **stk, unsigned int line_number)
{
	size_t len = 0;
	stack_t *temp = *stk;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack short\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	temp = *stk;
	*stk = (*stk)->next;

	temp->next = temp->next->next;
	temp->prev = *stk;
	(*stk)->next = temp;
	(*stk)->prev = NULL;
}
