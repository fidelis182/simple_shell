#include "simple_shell.c"

/**
 * file_comment - runs a command in a file
 * @file: path to get to the file
 * @addrep: valuce of last command
 * Return: value of last command
 */
int file_comment(char *file, int *addrep)
{
	ssize_t fl, rl, i;
	char buffer[120], *readline;
	unsigned int former = 120, new = 0;

	global_history = 0;
	fl = open(file, O_RDONLY);
	if (fl == -1)
	{
		*addrep = unable(file);
		return (*addrep);
	}
	readline = malloc(sizeof(char) * former);
	if (!readline)
		return (-1);
	while (rl)
	{
		rl = read(fl, buffer, 119);
		if (rl == 0 && new == 0)
			return (*addrep);
		buffer[rl] = '\0';
		new = new + rl;
		readline = realloc(readline, former, new);
		_strcat(readline, buffer);
		former = new;
	}
	for (i = 0; readline[i] == '\n'; i++)
		readline[i] = ' ';
	for (; i < new; i++)
	{
		if (readline[i] == '\n')
		{
			readline[i] = ';';
			for (i += 1; i < new && readline[i] == '\n'; i++)
				readline[i] = ' ';
		}
	}
	return (split_CallAndFree(i, readline, addrep, new));
}

/**
 * split_CallAndFree - splits calls and free
 * @a: input int
 * @line: input line to read
 * @addrep: input used to add rep
 * @new: input int
 * Return: 0 on success
 */
int split_CallAndFree(ssize_t a, char *line, int *addrep, unsigned int new)
{
	int rep;
	char **args, **begin;

	replace_environ(&line, addrep);
	_split_line(&line, new);
	args = _strtok(line, " ");
	free(line);
	if (!args)
		return (0);
	if (check_args(args) != 0)
	{
		*addrep = 2;
		free_args(args, args);
		return (*addrep);
	}
	begin = args;
	a = 0;
	while (args[a])
	{
		if (_strncmp(args[a], ";", 1) == 0)
		{
			free(args[a]);
			args[a] = NULL;
			rep = call_args(args, begin, addrep);
			args = &args[++a];
			a = 0;
		}
		a++;
	}
	rep = call_args(args, begin, addrep);
	free(begin);
	return (rep);
}

