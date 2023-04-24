#include "shell.h"

/**
 * env_linked_list - To create a linked list from env var
 * @env: environmental var
 * Return: link list
 */
list_t *env_linked_list(char **env)
{
	list_t *head;
	int j = 0;

	head = NULL;
	while (env[j] != NULL)
	{
		add_end_node(&head, env[j]);
		j++;
	}
	return (head);
}

/**
 * _env - prints environmental variables
 * @str: user's command into shell (i.e. "env")
 * @env: environmental variables
 * Return: 0 on successful
 */
int _env(char **str, list_t *env)
{
	free_double_ptr(str); /* frees usr input */
	print_list(env); /* prints environmental var */
	return (0);
}
