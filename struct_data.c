#include "monty.h"

/**
 * queue - Queue FIFO (first in first out)
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void queue(stack_t **stk, unsigned int line_number)
{
	(void)line_number;
	(void)*stk;

	flag.order = 0;
}


/**
 * _stack - Stack LIFO (last in first out)
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void _stack(stack_t **stk, unsigned int line_number)
{
	(void)line_number;
	(void)*stk;

	flag.order = 1;
}
