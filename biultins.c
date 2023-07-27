#include "simple_shell.h"

/**
 * builtin_env - prints all the current environment variables
 * @args: arguments array passed to shell
 * @beginning: pointer to the beginning of the arguments passed
 * Return: 0 if success else -1
 */
int builtin_env(char **args, char __attribute__((__unused__)) **beginning)
{
	int index;
	char new_line = '\n';

	if (!environ)
		return (-1);

	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], str_len(environ[index]));
		write(STDOUT_FILENO, &new_line, 1);
	}

	(void)args;
	return (0);
}
