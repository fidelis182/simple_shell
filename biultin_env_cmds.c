#include "simple_shell.h"

/**
 * current_env - prints all the current environment variables
 * @args: arguments array passed to shell
 * @begin: pointer to the beginning of the arguments passed
 * Return: 0 if success else -1
 */
int current_env(char **args, char __attribute__((__unused__)) **begin)
{
	int index;
	char new_line = '\n';

	if (!environ)
		return (-1);

	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, &new_line, 1);
	}

	(void)args;
	return (0);
}
/**
 * _setenv - adds or changes an environmental variable to the PATH.
 * @args: arguments array passed to shell
 * @begin: pointer to the beginning of the arguments passed
 * Return: 0 if success else -1
 */
int _setenv(char **args, char __attribute__((__unused__)) **begin)
{
	char **env = NULL, **new_env, *new_count;
	size_t size;
	int index;

	if (!args[0] || !args[1])
		return (generate_error(args, -1));
	new_count = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_count)
		return (generate_error(args, -1));
	_strcpy(new_count, args[0]);
	_strcat(new_count, "=");
	_strcat(new_count, args[1]);
	env = get_env(args[0]);
	if (env)
	{
		free(*env);
		*env = new_count;
		return (0);
	}

	size = 0;
	while (environ[size])
	{
		size++;
	}
	new_env = malloc(sizeof(char *) * (size + 2));
	if (!new_env)
	{
		free(new_count);
		return (generate_error(args, -1));
	}
	for (index = 0; environ[index]; index++)
		new_env[index] = environ[index];
	free(environ);
	environ = new_env;
	environ[index] = new_count;
	environ[index + 1] = NULL;

	return (0);
}
/**
 * _nsetenv - remove an environmental
 * variable from the PATH.
 * @args: arguments array passed to shell
 * @begin: pointer to the beginning of the
 * arguments passed
 * Return: 0 if success else -1
 */
int _unsetenv(char **args, char __attribute__((__unused__)) **begin)
{
	char **env, **new_env;
	size_t size;
	int index1, index2;

	if (!args[0])
		return (generate_error(args, -1));
	env = get_env(args[0]);
	if (!env)
		return (0);
	size = 0;
	while (environ[size])
	{
		size++;
	}
	new_env = malloc(sizeof(char *) * size);
	if (!new_env)
		return (generate_error(args, -1));
	for (index1 = 0, index2 = 0; environ[index1]; index1++)
	{
		if (*env == environ[index1])
		{
			free(*env);
			continue;
		}
		new_env[index2] = environ[index1];
		index2++;
	}
	free(environ);
	environ = new_env;
	environ[size - 1] = NULL;

	return (0);
}
