#include "shell.h"

/**
 * _which - enlarges command by appending it to a matching PATH directory
 * @str: first command user typed into shell (e.g. "ls" if user typed "ls -l")
 * @env: environmental var
 * Return: a cpy of enlarged command (e.g. "/bin/ls" if originally "ls")
 */
char *_which(char *str, list_t *env)
{
	char *pth, *cat = NULL, **toks;
	int d = 0;

	/* get and tokenize PATH directories, then free original string */
	pth = get_env("PATH", env);
	toks = c_str_tok(pth, ":");
	free(pth);

	/* append "/cmd" to each token to see it's legit */
	d = 0;
	while (toks[d] != NULL)
	{
		if (toks[d][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _strdup(toks[d]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			/* free tokens before returning legit enlarged path */
			free_double_ptr(toks);
			return (cat);
		}
		free(cat); /* free concatnated string if command is never found */
		d++;
	}
	free_double_ptr(toks);
	return (str); /* return str if not found; won't pass execve */
}

