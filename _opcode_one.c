#include "monty.h"

void the_push(stack_t **stk, unsigned int line_number);

/**
 * the_push - Pushes an element to the stack
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void the_push(stack_t **stk, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *temp = *stk;

	(void)line_number;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (*stk)
			free_list(stk);

		flag.opcode_flag = 0;
		return;
	}

	new_node->n = flag.number;
	if (flag.order)
	{
		new_node->prev = NULL;
		new_node->next = *stk;

		if (*stk)
			(*stk)->prev = new_node;

		*stk = new_node;
	}

	else
	{
		if (*stk)
		{
			while (temp->next)
				temp = temp->next;

			temp->next = new_node;
			new_node->prev = temp;
			new_node->next = NULL;
		}
		else
		{
			*stk = new_node;
			new_node->next = NULL;
			new_node->prev = NULL;
		}
	}
}


/**
 * the_pint - Prints the value at the top of the stack.
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines exceuted
*/
void the_pint(stack_t **stk, unsigned int line_number)
{
	if (!*stk)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	printf("%d\n", (*stk)->n);
}


/**
 * just_sub - Subtracts the top element of the stack from the second element
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void just_sub(stack_t **stk, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't subtract, stack short\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	temp = *stk;
	*stk = (*stk)->next;
	(*stk)->n -= temp->n;
	free(temp);
}


/**
 * just_div - divides the second and top element of the stack.
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void just_div(stack_t **stk, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't divide, stack short\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	if ((*stk)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	temp = *stk;
	*stk = (*stk)->next;
	(*stk)->n /= temp->n;
	free(temp);
}


/**
 * just_mul - Multiplies the second top and top element of the stack.
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void just_mul(stack_t **stk, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		flag.opcode_flag = 0;
		return;
	}

	temp = *stk;
	*stk = (*stk)->next;
	(*stk)->n *= temp->n;
	free(temp);
}
