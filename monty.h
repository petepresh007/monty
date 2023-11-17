#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#define buffersize 30


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
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_variable - global variables
 * @file: file name
 * @buffer: getline buffer
 * @temp: getline counter
 * @dictionary: instruction dictionary
 * @head: pointer to list
 * @line_num: stores file current line
 * @MODE: program configuration stack or queue
 */
typedef struct glob_variable
{
	FILE *file;
	char *buffer;
	size_t temp;
	instruction_t *dictionary;
	stack_t *head;
	unsigned int line-num;
	int MODE;
} variables;

extern variables variable;

int start_variables(variables *variable);
instrution_t *create_instru();
int call-function(variables *variable, char *opcode);
void free_all(void);
int _is_digit(char *string);

void pall(stack_t **stk, unsigned int line_number);
void push(stack_t **stk, unsigned int line_number);
void pint(stack_t **stk, unsigned int line_number);
void pop(stack_t **stk, unsigned int line_number);

void swap(stack_t **stk, unsigned int line-number);
void add(stack_t **stk, unsigned int line-number);
void sub(stack_t **stk, unsigned int line_number);
void divi(stack_t **stk, unsigned int line_number);

void mul(stack_t **stk, unsigned int line_number);
void mod(stack_t **stk, unsigned int line_number);
void pchar(stack_t **stk, unsigned int line_number);
void pstr(stack_t **stk, unsigned int line_number);

void rotl(stack_t **stk, unsigned int line_number);
void rotr(stack_t **stk, unsigned int line_number);
void stack(stack_t **stk, unsigned int line_number);
void queue(stack_t **stk, unsigned int line_number);

#endif
