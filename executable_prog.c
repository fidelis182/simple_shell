#include "simple_shell.h"

/**
 * execution_prog - executes commands entered by users
 *@cp: command
 *@cmd:vector array of pointers to commands
 * Return: 0
 */
void execution_prog(char *cp, char **cmd)
{
	pid_t pid;
	int status;
	char **env = environ;

	pid = fork();
	if (pid < 0)
		perror(cp);
	if (pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		buffers(cmd);
		exit(98);
	}
	else
		wait(&status);
}
