#ifndef MONTY_H
#define MONTY_H

#define READ_BUFFER 1024
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct data_hub - contains data
 * @opcode_flag: Checks for malloc
 * @number: Integer to push to stack
 * @order: The order to include elements
*/
typedef struct data_hub
{
	int opcode_flag;
	int number;
	int order;
} data;

extern data flag;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stk, unsigned int line_number);
} instruction_t;


void get_input(FILE *file);
int execute(char *, unsigned int, stack_t **);
void the_push(stack_t **, unsigned int);
void the_pall(stack_t **, unsigned int);
void the_push(stack_t **, unsigned int);
void free_array(char **);
char *_isdigit(char *);
void free_list(stack_t **);
int isempty(char *str);
void the_pint(stack_t **stk, unsigned int line_number);
void the_pop(stack_t **stk, unsigned int line_number);
void the_swap(stack_t **stk, unsigned int line_number);
void nop(stack_t **stk, unsigned int line_number);
void just_add(stack_t **stk, unsigned int line_number);
void just_sub(stack_t **stk, unsigned int line_number);
void just_div(stack_t **stk, unsigned int line_number);
void just_mul(stack_t **stk, unsigned int line_number);
void the_mod(stack_t **stk, unsigned int line_number);
void pchar(stack_t **stk, unsigned int line_number);
void pstr(stack_t **stk, unsigned int line_number);
void rotl(stack_t **stk, unsigned int line_number);
void rotr(stack_t **stk, unsigned int line_number);
void queue(stack_t **stk, unsigned int line_number);
void _stack(stack_t **stk, unsigned int line_number);

#endif
