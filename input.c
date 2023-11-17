#include "monty.h"

/**
* get_input - Takes in user input and returns it as a string
* @file: File descriptor to read from
* Return: String or NULL if it fails
*/
void get_input(FILE *file)
{
	unsigned int line_number = 0;
	char *file_input = NULL;
	stack_t *stk = NULL;
	int status;
	size_t n;

	while (getline(&file_input, &n, file) != -1)
	{
		line_number++;
		if (isempty(file_input) == 1)
			continue;
		status = execute(file_input, line_number, &stk);
		if (status != 0)
		{
			free(file_input);
			if (stk)
				free_list(&stk);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
	free(file_input);
	free_list(&stk);
}
