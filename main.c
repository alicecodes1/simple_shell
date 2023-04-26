#include "shell.h"

/**
 * main - creates a simple shell
 * @ac: argument count
 * @av: argument vec
 * @env: env var
 * Return: 0 on successful
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	prompt(env);

	return (0);
}
