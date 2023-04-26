#include "shell.h"

/**
 * env_linked_list - To create a linked list from env var
 * @env: environ var
 * Return: link list
 */
list_t *env_linked_list(char **env)
{
	list_t *head;
	int h = 0;

	head = NULL;
	while (env[j] != NULL)
	{
		add_end_node(&head, env[j]);
		h++;
	}
	return (head);
}

/**
 * _env - to print env var
 * @str: user's commnd into shell (i.e. "env")
 * @env: env var
 * Return: 0 on successful
 */
int _env(char **str, list_t *env)
{
	free_double_ptr(str); /* frees usr input */
	print_list(env);
	return (0);
}
