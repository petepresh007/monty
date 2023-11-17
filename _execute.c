#include "monty.h"

int execute(char *file_input, unsigned int line_no, stack_t **stk);
data flag;

/**
 * execute - Executes opcodes in each line in a monty ByteCode file
 * @file_input: An array of strings of each line in ByteCode file
 * @line_no: Line number processed in file
 * @stk: A double pointer to the head of the list
 * Return: 0 on success or 1 when it fails
*/

int execute(char *file_input, unsigned int line_no, stack_t **stk)
{
	char *tokens, **tokenized_array;
	int idx = 0, j = 0, status = 1;
	instruction_t opcodes[] = {
		{"push", the_push}, {"pall", the_pall}, {"pint", the_pint},
		{"pop", the_pop}, {"swap", the_swap}, {"nop", nop},
		{"add", just_add}, {"sub", just_sub}, {"div", just_div},
		{"mul", just_mul}, {"mod", the_mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{"queue", queue}, {"stack", _stack}, {NULL, NULL}
	};

	my_data.opcode_my_data = 1;
	my_data.number = 0;

	tokenized_array = malloc(sizeof(char *) * READ_BUFFER);
	if (!tokenized_array)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

	tokens = strtok(file_input, " \t\r\n");

	while (tokens)
	{
		tokenized_array[j] = strdup(tokens);
		if (!tokenized_array[j])
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_array(tokenized_array);
			return (EXIT_FAILURE);
		}
		j++;
		tokens = strtok(NULL, " \t\r\n");
	}
	tokenized_array[j] = NULL;

	while (opcodes[idx].opcode)
	{
		if (strcmp(tokenized_array[0], opcodes[idx].opcode) == 0)
		{
			if (idx == 0)
			{
				if (_isdigit(tokenized_array[1]))
				{
					my_data.number = atoi(tokenized_array[1]);
					the_push(stk, line_no);
					status = 0;
					break;
				}
				fprintf(stderr, "L%d: usage: push integer\n", line_no);
				free_array(tokenized_array);
				return (EXIT_FAILURE);
			}
			opcodes[idx].f(stk, line_no);
			status = 0;
			break;
		}
		idx++;
	}
	if (status && tokenized_array)
	{
		fprintf(stderr, "L%d: invalid instruction %s\n", line_no,
				tokenized_array[0]);
		free_array(tokenized_array);
		return (EXIT_FAILURE);
	}
	free_array(tokenized_array);

	if (!my_data.opcode_my_data)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
