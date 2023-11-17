#ifndef MONTY_H
#define MONTY_H

#define READ_BUFFER     1024
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

typedef struct data_hub
{
	int opcode_my_data;
	int number;
	int order;
} data;

extern data my_data;

char **get_input(FILE *);
int execute(char *, unsigned int, stack_t **);
void the_push(stack_t **stk, unsigned int);
void the_pall(stack_t **stk, unsigned int);
void free_array(char **);
void the_push(stack_t **stk, unsigned int);
char *_the_isdigit(char *);
void free_list(stack_t **);
int isempty(char *str);
void the_pint(stack_t **stk, unsigned int line_number);
void the_pop(stack_t **stk, unsigned int line_number);
void the_swap(stack_t **stk, unsigned int line_number);
void the_nop(stack_t **stk, unsigned int line_number);
void the_add(stack_t **stk, unsigned int line_number);
void the_sub(stack_t **stk, unsigned int line_number);
void the_div(stack_t **stk, unsigned int line_number);
void the_mul(stack_t **stk, unsigned int line_number);
void the_mod(stack_t **stk, unsigned int line_number);
void the_pchar(stack_t **stk, unsigned int line_number);
void the_pstr(stack_t **stk, unsigned int line_number);
void the_rotl(stack_t **stk, unsigned int line_number);
void the_rotr(stack_t **stk, unsigned int line_number);
void the_queue(stack_t **stk, unsigned int line_number);
void the_stack(stack_t **stk, unsigned int line_number);

#endif
