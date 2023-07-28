#include "simple_shell.h"

/**
 * execution_prog - executes commands entered by users
 *@command: command
 *@cmd:vector array of pointers to commands
 * Return: 0
 */
void execution_prog(char *command, char **cmd)
{
	pid_t pid;
	int status;
	char **env = environ;

	pid = fork();
	if (pid < 0)
		perror(command);
	if (pid == 0)
	{
		execve(command, cmd, env);
		perror(command);
		free(command);
		free_buff(cmd);
		exit(98);
	}
	else
		wait(&status);
}
