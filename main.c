#include "simple_shell.h"

/**
* main - carries out the read, execute then print output loop
* @ac: argument count
* @av: argument vector
* @envp: environment vector
*
* Return: 0
*/

int main(int ac, char **av, char *envp[])
{
	char *new_line = NULL, *pathcd = NULL, *path = NULL;
	size_t buffersize = 0;
	ssize_t linesize = 0;
	char **command = NULL, **paths = NULL;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, handle_signal);
	while (1)
	{
		free_buff(command);
		free_buff(paths);
		free(pathcd);
		prompt();
		linesize = get_line(&new_line, &buffersize, stdin);
		if (linesize < 0)
			break;
		info.ln_count++;
		if (new_line[linesize - 1] == '\n')
			new_line[linesize - 1] = '\0';
		command = tokenizing(line);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (biultin_checker(command, line))
			continue;
		path = findpath();
		paths = tokenizing(path);
		pathcd = testpath(paths, command[0]);
		if (!pathcd)
			perror(av[0]);
		else
			execution_prog(pathcd, command);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(new_line);
	return (0);
}
