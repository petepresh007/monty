#include "monty.h"

/**
 * the_pall - prints all the values on the stack.
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void the_pall(stack_t **stk, unsigned int line_number)
{
    stack_t *tmp;

    (void)line_number;

    if (!*stk)
        return;

    tmp = *stk;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

/**
 * the_nop - just there
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void the_nop(stack_t **stk, unsigned int line_number)
{
    (void)*stk;
    (void)line_number;
}

/**
 * the_add - Adds elements to the stack
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void the_add(stack_t **stk, unsigned int line_number)
{
    stack_t *tmp = *stk;
    size_t len = 0;

    while (tmp)
    {
        len++;
        tmp = tmp->next;
    }

    if (len < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        my_data.opcode_my_data = 0;
        return;
    }

    tmp = *stk;
    *stk = (*stk)->next;
    (*stk)->n += tmp->n;
    free(tmp);
}

/**
 * the_pop - Removes the top element of the stack
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void the_pop(stack_t **stk, unsigned int line_number)
{
    stack_t *tmp = *stk;

    if (!*stk)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        my_data.opcode_my_data = 0;
        return;
    }

    *stk = (*stk)->next;
    free(tmp);
}

/**
 * the_swap - Swaps the top two elements of the stack
 * @stk: A double pointer to the head of the stack_t list
 * @line_number: Lines executed
*/
void the_swap(stack_t **stk, unsigned int line_number)
{
    size_t len = 0;
    stack_t *tmp = *stk;

    while (tmp)
    {
        len++;
        tmp = tmp->next;
    }

    if (len < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        my_data.opcode_my_data = 0;
        return;
    }

    tmp = *stk;
    *stk = (*stk)->next;

    tmp->next = tmp->next->next;
    tmp->prev = *stk;
    (*stk)->next = tmp;
    (*stk)->prev = NULL;
}
