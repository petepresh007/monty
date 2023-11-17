#include "monty.h"
variables variable;

/* Function prototype for getline */
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
/**
 * main - Start LIFO, FILO program
 * @argumentc: Number of arguments
 * @argumentv: Pointer containing arguments
 * Return: 0 Success, 1 Failure
 */
int main(int argumentc, char **argumentv)
{
	char *opcode;

	if (argumentc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (start_variables(&variable) != 0)
		return (EXIT_FAILURE);
	variable.file = fopen(argumentv[1], "r");
	if (!variable.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argumentv[1]);
		free_all();
		return (EXIT_FAILURE);
	}

	while (getline(&variable.buffer, &variable.temp, variable.file) != EOF)
	{
		opcode = strtok(variable.buffer, " \r\t\n");
		if (opcode != NULL)
			if (call_function(&variable, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		variable.line_num++;
	}
	free_all();

	return (EXIT_SUCCESS);
}
