#include "simple_shell.h"

/**
 * command_error - creates error message for command not found errors
 * @args: arguments array passed as command.
 * Return: error string.
 */
char *command_error(char **args)
{
	char *err, *history_str;
	int length;

	history_str = _itoa(global_history);
	if (!history_str)
		return (NULL);

	length = str_len(s) + str_len(history_str) + str_len(args[0]) + 16;
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
	_strcat(err, ": not found\n");

	free(history_str);
	return (err);
}

/**
 * denied_permission - creates error message for permission denied errors
 * @args: arguments array passed as command.
 * Return: error string.
 */
char *denied_permission(char **args)
{
	char *err, *history_str;
	int length;

	history_str = _itoa(global_history);
	if (!history_str)
		return (NULL);

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
	_strcat(err, ": ");
	_strcat(err, args[0]);
	_strcat(err, ": Permission denied\n");

	free(history_str);
	return (err);
}

