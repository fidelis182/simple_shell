#include "simple_shell.c"

/**
 * arguments - handle arguments.
 * @ command: last executed command return value
 * Return: if end-of-file is -2, if cant split -1 else 0
 */
int arguments(int *command)
{
	int command_return = 0, index;
	char **args, *line = NULL, **begin;

	line = get_args(line, command);
	if (!line)
		return (EOF_CODE);

	args = _strtok(line, " ");
	free(line);
	if (!args)
		return (command_return);
	if (check_args(args) != 0)
	{
		*command = 2;
		free_args(args, args);
		return (*command);
	}
	begin = args;

	for (index = 0; args[index]; index++)
	{
		if (_strncmp(args[index], ";", 1) == 0)
		{
			free(args[index]);
			args[index] = NULL;
			command_return = call_args(args, begin, command);
			args = &args[++index];
			index = 0;
		}
	}
	if (args)
		command_return = call_args(args, begin, command);

	free(begin);
	return (command_return);
}
/**
 * get_args - gets a command from input
 * @line: buffer to store the command
 * @command: last executed command return value
 * Return: a pointer to the stored command, if an error occurrents returns NULL
 */
char *get_args(char *line, int *command)
{
	size_t i = 0;
	ssize_t read;
	char *prompt = "fidie$ ";

	if (line)
		free(line);

	read = _get_line(&line, &i, STDIN_FILENO);
	if (read == -1)
		return (NULL);
	if (read == 1)
	{
		global_history++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 8);
		return (get_args(line, command));
	}

	line[read - 1] = '\0';
	replace_environ(&line, command);
	_split_line(&line, read);

	return (line);
}
/**
 * check_args - checks if there are any leading ';', ';;', '||', or '&&'.
 * @args: 2D pointer to tokenized commands and arguments
 * Return: 2 if a ';', '&&', or '||' is placed at an invalid position else 0
 */
int check_args(char **args)
{
	size_t j;
	char *current, *another;

	for (j = 0; args[j]; j++)
	{
		current = args[j];
		if (current[0] == ';' || current[0] == '&' || current[0] == '|')
		{
			if (j == 0 || current[1] == ';')
				return (generate_error(&args[j], 2));
			another = args[j + 1];
			if (another && (another[0] == ';' || another[0] == '&' || another[0] == '|'))
				return (generate_error(&args[j + 1], 2));
		}
	}
	return (0);
}

/**
 * call_args - splits operators from commands and calls them.
 * @args: arguments array
 * @begin: pointer to the beginning of args
 * @command: last executed command return value
 * Return: The return value of the last executed command
 */
int call_args(char **args, char **begin, int *command)
{
	int command_return, index;

	if (!args[0])
		return (*command);
	for (index = 0; args[index]; index++)
	{
		if (_strncmp(args[index], "||", 2) == 0)
		{
			free(args[index]), args[index] = NULL, args = _replace_alias(args);
			command_return = run_ar(args, begin, command);
			if (*command != 0)
			{
				args = &args[++index], index = 0;
			}
			else
			{
				for (index++; args[index]; index++)
					free(args[index]);
				return (command_return);
			}
		}
		else if (_strncmp(args[index], "&&", 2) == 0)
		{
			free(args[index]), args[index] = NULL, args = _replace_alias(args);
			command_return = run_args(args, begin, command);
			if (*command == 0)
			{
				args = &args[++index], index = 0;
			}
			else
			{
				for (index++; args[index]; index++)
					free(args[index]);
				return (command_return);
			}
		}
	}
	args = _replace_alias(args);
	command_return = run_args(args, begin, command);
	return (command_return);
}
/**
 * run_args - Calls the execution of a command.
 * @args: An array of arguments.
 * @begin: A double pointer to the beginning of args.
 * @command: last executed command return value
 * Return: value of the last executed command.
 */
int run_args(char **args, char **begin, int *command)
{
	int command_return, j;
	int (*builtin_func)(char **args, char **begin);

	builtin_func = _get_builtin_func(args[0]);

	if (builtin_func)
	{
		command_return = builtin_func(args + 1, begin);
		if (command_return != EXIT_CODE)
			*command = command_return;
	}
	else
	{
		*command = exec(args, begin);
		command_return = *command;
	}

	global_history++;

	for (j = 0; args[j]; j++)
		free(args[j]);

	return (command_return);
}
