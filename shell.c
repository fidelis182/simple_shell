#include "simple_shell.h"
/**
 * main - the entry to the program
 * @ac: the number of argument
 * @av: list of arg or prog
 * Return: last executed command
 */

int main(int ac, char *av[])
{
	char *prompt = "fidie$ ", *ln = "\n";
	int rep = 0, reppin, *addrep = &reppin;
	char *s;

	global_alias = NULL, global_history = 1, s = av[0];
	signal(SIGINT, handle_signal);
	*addrep = 0;
	environ = copy_env();
	if (!environ)
		exit(-20);
	if (ac != 1)
	{
		rep = file_comment(av[1], addrep);
		free_env();
		free_list(global_alias);
		return (*addrep);
	}
	if (!isatty(STDIN_FILENO))
	{
		while (rep != -2 && rep != -3)
			rep = arguments(addrep);
		free_env();
		free_list(global_alias);
		return (*addrep);
	}
	while (1)
	{
		write(STDOUT_FILENO, prompt, 8);
		rep = arguments(addrep);
		if (rep == -2 || rep == -3)
		{
			if (rep == -2)
				write(STDOUT_FILENO, ln, 1);
			free_env();
			free_list(global_alias);
			exit(*addrep);
		}
	}
	free_env();
	free_list(global_alias);
	return (*addrep);
}
