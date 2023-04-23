#include "shell.h"

/**
 * c_exit - frees user's typed cmd & linked ls before exiting
 * @str: user's typed cmd
 * @env: input the linked ls of envirnment
 */
void c_exit(char **str, ls_t *env)
{
	free_double_ptr(str);
	free_linked_ls(env);
	_exit(0);
}

/**
 * _execve - execute cmd user typed into shell
 * @s: cmd user typed
 * @env: env variable
 * @num: nth user cmd; to be used in erroror msg
 * Return: 0 on success
 */
int _execve(char **s, ls_t *env, int num)
{
	char *holder;
	int stt = 0, t = 0;
	pid_t pid;

	/* check if cmd is absolute path */
	if (access(s[0], F_OK) == 0)
	{
		holder = s[0];
		t = 1;
	}
	else
		holder = _which(s[0], env);
	/* if not an exe, free */
	if (access(holder, X_OK) != 0)
	{
		not_found(s[0], num, env);
		free_double_ptr(s);
		return (127);
	}
	else /* else fork & execute exe cmd */
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(holder, s, NULL) == -1)
			{
				not_found(s[0], num, env);
				c_exit(s, env);
			}
		}
		else
		/* if parent, wait for child then free all */
		{
			wait(&stt);
			free_double_ptr(s);
			if (t == 0)
				free(holder);
		}
	}
	return (0);
}
