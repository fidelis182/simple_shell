#include "simple_shell.h"
/**
 * get_builtin - looks for builtin functions
 * @command: The command to check
 * Return: corresponding builtin function
 */
int (*get_builtin(char *command))(char **args, char **begin)
{
	biultin builtin_funcs[] = {
		{ "cd", biultin_command},
		{ "env", create_env},
		{ "exit", exit_biultin },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "alias", builtin_alias },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin_funcs[i].s; i++)
	{
		if (_strcmp(builtin_funcs[i].s, command) == 0)
			break;
	}
	return (builtin_funcs[i].func);
} 

/**
 * exit_biultin - builtin function that terminates the process shell process
 * @args: arguments array
 * @begin: pointer to the beginning of the arguments passed
 * Return: -3 if there are no arguments, -2 if invalid 0 otherwise
 */
int exit_biultin(char **args, char **begin)
{
	unsigned int num = 0, max = 1 << (sizeof(int) * 8 - 1);
	int i, len = 10;

	if (args[0])
	{
		if (args[0][0] == '+')
		{
			i = 1;
			len++;
		}
		for (; args[0][i]; i++)
		{
			if (i <= len && args[0][i] <= '9' && args[0][i] >= '0')
				num = (num * 10) + (args[0][i] - '0');
			else
				return (generate_error(--args, 2));
		}
	}
	else
	{
		return (-3);
	}
	if (num > max - 1)
		return (generate_error(--args, 2));
	args -= 1;
	free_args(args, begin);
	free_env();
	free_list(global_alias);
	exit(num);
}
/**
 * builtin_command - used to change the current directory
 * @args: arguments array
 * @begin: pointer to the beginning of the arguments
 * Return: 2 if not a directory, -1 if contains error otherwise 0
 */
int builtin_command(char **args, char __attribute__((__unused__)) **begin)
{
	char *old_pwd = NULL, *pwd = NULL;
	struct stat s;

	old_pwd = getcwd(old_pwd, 0);
	if (!old_pwd)
		return (-1);
	if (args[0])
	{
		if (*(args[0]) == '-' || _strcmp(args[0], "--") == 0)
		{
			if ((args[0][1] == '-' && args[0][2] == '\0') ||
					args[0][1] == '\0')
			{
				if (get_env("OLDPWD") != NULL)
					(chdir(*get_env("OLDPWD") + 7));
			}
			else
			{
				free(old_pwd);
				return (generate_error(args, 2));
			}
		}
		else
		{
			if (stat(args[0], &s) == 0 && S_ISDIR(s.st_mode)
					&& ((s.st_mode & S_IXUSR) != 0))
				chdir(args[0]);
			else
			{
				free(old_pwd);
				return (generate_error(args, 2));
			}
		}
	}
	else
	{
		if (get_env("HOME") != NULL)
			chdir(*(ge_env("HOME")) + 5);
	}
	return (changeDirectory(args, pwd, old_pwd));
}

/**
 * changeDirectory - used to change the current directory
 * @args: arguments array
 * @pwd: pointer to the beginning of the arguments
 * @old_pwd: pointer to the beginning of the arguments
 * Return: 2 if not a directory, -1 if contains error otherwise 0
 */
int changeDirectory(char **args, char *pwd, char *old_pwd)
{
	char **details, *new_line = "\n";

	pwd = getcwd(pwd, 0);
	if (!pwd)
		return (-1);
	details = malloc(sizeof(char *) * 2);
	if (!details)
		return (-1);

	details[0] = "OLDPWD";
	details[1] = old_pwd;
	if (_setenv(details, details) == -1)
		return (-1);
	details[0] = "PWD";
	details[1] = pwd;
	if (_setenv(details, details) == -1)
		return (-1);
	if (args[0] && args[0][0] == '-' && args[0][1] != '-')
	{
		write(STDOUT_FILENO, pwd, _strlen(pwd));
		write(STDOUT_FILENO, new_line, 1);
	}
	free(old_pwd);
	free(pwd);
	free(details);
	return (0);
}
