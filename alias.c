#include "simple_shell.h"

/**
 * _replace_alias - replaces any matching alias
 * @args: arguments passed.
 * Return: char pointer to the arguments.
 */
char **_replace_alias(char **args)
{
	alias_t *temp_alias;
	int i;
	char *new_value;

	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (i = 0; args[i]; i++)
	{
		temp_alias = global_alias;
		while (temp_alias)
		{
			if (_strcmp(args[i], temp_alias->s) == 0)
			{
				new_value = malloc(sizeof(char) * (_strlen(temp_alias->count) + 1));
				if (!new_value)
				{
					free_args(args, args);
					return (NULL);
				}
				_strcpy(new_value, temp_alias->count);
				free(args[i]);
				args[i] = new_value;
				i--;
				break;
			}
			temp_alias = temp_alias->another;
		}
	}

	return (args);
}

/**
 * set_alias - sets an existing alias 'source' with a new value
 * @s: alias source
 * @count: alias value
 */
void set_alias(char *s, char *count)
{
	alias_t *temp_alias = global_alias;
	int length, j, k;
	char *new_count;

	*count = '\0';
	count++;
	length = _strlen(count) - _strspn(count, "'\"");
	new_count = malloc(sizeof(char) * (length + 1));
	if (!new_count)
		return;
	for (j = 0, k = 0; count[j]; j++)
	{
		if (count[j] != '\'' && count[j] != '"')
			new_count[k++] = count[j];
	}
	new_count[k] = '\0';
	while (temp_alias)
	{
		if (_strcmp(s, temp_alias->s) == 0)
		{
			free(temp_alias->count);
			temp_alias->count = new_count;
			break;
		}
		temp_alias = temp_alias->another;
	}
	if (!temp_alias)
		add_alias_end(&global_alias, s, new_count);
}

/**
 * builtin_alias - builtin command  used to print all global_alias or set alias
 * @args: arguments array
 * @begin: pointer to the beginning of the arguments passed
 * Return: 0 and -1 if has error
 */
int builtin_alias(char **args, char __attribute__((__unused__)) **begin)
{
	alias_t *temp_alias = global_alias;
	int i, ret = 0;
	char *count;

	if (!args[0])
	{
		while (temp_alias)
		{
			print_alias(temp_alias);
			temp_alias = temp_alias->another;
		}
		return (ret);
	}
	for (i = 0; args[i]; i++)
	{
		temp_alias = global_alias;
		count = _strchr(args[i], '=');
		if (!count)
		{
			while (temp_alias)
			{
				if (_strcmp(args[i], temp_alias->s) == 0)
				{
					print_alias(temp_alias);
					break;
				}
				temp_alias = temp_alias->another;
			}
			if (!temp_alias)
				ret = generate_error(args + i, 1);
		}
		else
			set_alias(args[i], count);
	}
	return (ret);
}

/**
 * print_alias - prints alias in source to value format.
 * @alias: pointer to alias.
 */
void print_alias(alias_t *alias)
{
	char *alias_str;
	int length = _strlen(alias->s) + _strlen(alias->count + 4;

	alias_str = malloc(sizeof(char) * (length + 1));
	if (!alias_str)
		return;
	_strcpy(alias_str, alias->s);
	_strcat(alias_str, "='");
	_strcat(alias_str, alias->count);
	_strcat(alias_str, "'\n");

	write(STDOUT_FILENO, alias_str, length);
	free(alias_str);
}
