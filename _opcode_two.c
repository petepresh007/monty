#include "monty.h"

/**
 * the_mod - Computes the rest of division of the second top element
 *       by the top element of the stack.
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void the_mod(stack_t **stk, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		my_data.opcode_my_data = 0;
		return;
	}

	if ((*stk)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		my_data.opcode_my_data = 0;
		return;
	}

	temp = *stk;
	*stk = (*stk)->next;
	(*stk)->n %= temp->n;
	free(temp);
}

/**
 * pchar -  Prints the char at the top of the stack.
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/

void pchar(stack_t **stk, unsigned int line_number)
{
	(void)line_number;

	if (!*stk)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		my_data.opcode_my_data = 0;
		return;
	}

	if ((*stk)->n < 0 || (*stk)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value not okay\n", line_number);
		my_data.opcode_my_data = 0;
		return;
	}

	putchar((*stk)->n);
	putchar('\n');

}


/**
 * pstr - Prints string starting from the top of the stack
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/

void pstr(stack_t **stk, unsigned int line_number)
{
	stack_t *temp = *stk;

	(void)line_number;

	while (temp)
	{
		if (temp->n == 0 || temp->n < 0 || temp->n > 127)
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}


/**
 * rotl - Rotates the stack to the top
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void rotl(stack_t **stk, unsigned int line_number)
{
	stack_t *temp = *stk, *current = *stk;
	size_t len = 0;

	(void)line_number;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
		return;

	temp = *stk;

	while (temp->next)
		temp = temp->next;

	*stk = (*stk)->next;
	temp->next = current;
	(*stk)->prev = NULL;
	current->next = NULL;
	current->prev = temp;
}


/**
 * rotr - Rotates the stack to the bottom
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void rotr(stack_t **stk, unsigned int line_number)
{
	stack_t *temp = *stk, *current = *stk;
	size_t len = 0;

	(void)line_number;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
		return;

	temp = *stk;

	while (temp->next)
		temp = temp->next;

	temp->prev->next = NULL;
	*stk = temp;
	(*stk)->prev = NULL;
	(*stk)->next = current;
	current->prev = *stk;
}
