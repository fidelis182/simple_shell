#include "simple_shell.h"

/**
 * exit_error - creates error message for builtin_exit errors.
 * @args: arguments array passed as command.
 * Return: error string.
 */
char *error_exit(char **args)
{
	char *err, *history_str;
	int length;

	history_str = _itoa(global_history);
	if (!history_str)
		return (NULL);

	length = str_len(s) + str_len(history_str) + str_len(args[0]) + 27;
	err = malloc(sizeof(char) * (length + 1));
	if (!err)
	{
		free(history_str);
		return (NULL);
	}

	_strcpy(err, s);
	_strcat(err, ": ");
	_strcat(err, history_str);
	_strcat(err, ": exit: Illegal number: ");
	_strcat(err, args[0]);
	_strcat(err, "\n");

	free(history_str);
	return (err);
}
/**
 * biultin_cd_error - creates error message for builtin_cd errors.
 * @args: arguments array passed as command.
 * Return: error string.
 */
char *biultin_cd_error(char **args)
{
	char *err, *history_str;
	int length;

	history_str = _itoa(global_history);
	if (!history_str)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';
	length = _strlen(s) + _strlen(history_str) + _strlen(args[0]) + 24;
	err = malloc(sizeof(char) * (length + 1));
	if (!err)
	{
		free(history_str);
		return (NULL);
	}

	_strcpy(err, s);
	_strcat(err, ": ");
	_strcat(err, history_str);
	if (args[0][0] == '-')
		_strcat(err, ": cd: Illegal option ");
	else
		_strcat(err, ": cd: can't cd to ");
	_strcat(err, args[0]);
	_strcat(err, "\n");

	free(history_str);
	return (err);
}

/**
 * syntax_error - creates error message for syntax errors.
 * @args: arguments array passed as command.
 * Return: error string.
 */
char *syntax_error(char **args)
{
	char *err, *history_str;
	int length;

	history_str = _itoa(global_history);
	if (!history_str)
		return (NULL);

	length = _strlen(s) + _strlen(history_str) + _strlen(args[0]) + 33;
	err = malloc(sizeof(char) * (length + 1));
	if (!err)
	{
		free(history_str);
		return (NULL);
	}

	_strcpy(err, s);
	_strcat(err, ": ");
	_strcat(err, history_str);
	_strcat(err, ": Syntax error: \"");
	_strcat(err, args[0]);
	_strcat(err, "\" unexpected\n");

	free(history_str);
	return (err);
}

/**
 * biultin_alias_error - creates error message for builtin_alias errors.
 * @args: arguments array passed as command.
 * Return: error string.
 */
char *biultin_alias_error(char **args)
{
	char *err;
	int length;

	length = _strlen(s) + _strlen(args[0]) + 13;
	err = malloc(sizeof(char) * (length + 1));
	if (!err)
		return (NULL);

	_strcpy(err, "alias: ");
	_strcat(err, args[0]);
	_strcat(err, " not found\n");

	return (err);
}

/**
 * biultin_env_error - creates error message for builtin_env errors.
 * @args: arguments array passed as command.
 * Return: error string.
 */
char *biultin_env_error(char **args)
{
	char *err, *history_str;
	int length;

	history_str = _itoa(global_history);
	if (!history_str)
		return (NULL);

	args--;
	length = _strlen(s) + _strlen(history_str) + _strlen(args[0]) + 45;
	err = malloc(sizeof(char) * (length + 1));
	if (!err)
	{
		free(history_str);
		return (NULL);
	}

	_strcpy(err, s);
	_strcat(err, ": ");
	_strcat(err, history_str);
	_strcat(err, ": ");
	_strcat(err, args[0]);
	_strcat(err, ": Unable to add/remove from environment\n");

	free(history_str);
	return (err);
}
