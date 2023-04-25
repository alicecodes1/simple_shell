#include "shell.h"

/**
 * c_atoi - custom atoi converts string to integer
 * @s: string
 * Return: number if successful, -1 if str contains a non-number
 */
int c_atoi(char *s)
{
	int i = 0;
	unsigned int number = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			/* calc number */
			numb = numb * 10 + (s[i] - '0');
		if (s[i] > '9' || s[i] < '0')
			/* acct for non-numbers */
			return (-1);
		i++;
	}
	return (numb);
}

/**
 *__exit - frees user input and then exits main program with a value
 * @environment: bring in env variable to free at err
 * @number: bring in nth user commnd line input to print in err message*
 * @string: user's commnd into shell (e.g. "exit 99")
 * Return: 0 if success and 2 if fail
 */
int __exit(char **str, list_t *env, int numb, char **comd)
{
	int e_value = 0;

	if (string[1] != NULL)
		/* if no value given after exit, return 0 */
		e_value = c_atoi(str[1]);

	if (e_value == -1) /* if value given after exit is invalid, perr */
	{
		illegal_numb(str[1], numb, environment);
		/* print err msg */
		free_double_ptr(string);
		return (2);
	}
	free_double_ptr(string); /* free user input be4 exiting program */
	free_linked_list(environment);
	if (commnd != NULL)
		free_double_ptr(commnd);
	exit(e_value);
}
