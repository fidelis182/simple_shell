#include "simple_shell.h"
/**
 * main - the entry to the program
 * @ac: the number of argument
 * @av: list of arg or prog
 * @envp: environment vector
 * Return: last executed command
 */

int main(int ac, char **av, char *envp[])
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t buffer = 0;
	ssize_t line_size = 0;
	char **command = NULL, **paths = NULL;
	(void)envp, (void)av;

	if (ac < 1)
		return (-1);
	signal(SIGINT, handle_signal);
	while (1)
	{
		prompt();
		line_size = getline(&line, &buffer, stdin);
		if (line_size < 0)
			break;
		info.ln_count++;
		if (line[line_size - 1] == '\n')
			line[line_size - 1] = '\0';
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (!pathcommand)
			perror(av[0]);
	}
	if (line_size < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
