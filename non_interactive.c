#include "shell.h"

/**
 * c_ignore -  ignores spaces and newlines
 * (e.g. echo "ls\n ls" | ./a.out)
 * @str: envrion var
 * Return: new str
 */
char *c_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

/**
 * non_interactive - handles when user pipes commds into shell via pipeline
 * (e.g. echo "ls/nls -al/n" | ./a.out)
 * @env: envr var
 */
void non_interactive(list_t *env)
{
	size_t k = 0, n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command = NULL, *n_command = NULL, **n_line, **token;

	k = get_line(&command);
	if (k == 0)
	{
		free(command);
		exit(0);
	}
	n_command = command;
	command = c_ignore(command);
	n_line = _str_tok(command, "\n");
	if (n_command != NULL)
		free(n_command);
	n = 0;
i	while (n_line[n] != NULL)
	{
		command_line_no++;
		token = NULL;
		token = _str_tok(n_line[n], " ");
		exit_stat = built_in(token, env, command_line_no, n_line);
		if (exit_stat)
		{
			n++;
			continue;
		}
		exit_stat = _execve(token, env, command_line_no);
		n++;
	}
	free_double_ptr(n_line);
	free_linked_list(env);
	exit(exit_stat);
}
