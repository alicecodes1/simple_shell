#include "shell.h"

/**
 * free_double_ptr - free malloced arrays of strigs
 *
 * @str: array of strings
 */
void free_double_ptr(char **str)
{
	int in = 0;

	while (str[in] != NULL)
	{
		free(str[in]);
		in++;
	}
	free(str); /* free arrays */
}
