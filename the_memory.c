#include "monty.h"

/**
 * free_array - Frees malloc for an array
 * @array: Array to free
*/
void free_array(char **array)
{
	int i = 0;

	if (!array)
		return;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
