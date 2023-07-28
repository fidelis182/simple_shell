#include "simple_shell.h"

/**
* builtin_func - handles execution of builtin functions
* @cmd: tokenized commands
* @new_line: input read from stdin
*
* Return: 1 if executed, 0 if not
*/
int builtin_func(char **cmd, char *new_line)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*cmd, builtin.env) == 0)
	{
		printenv();
		return (1);
	}
	else if (_strcmp(*cmd, builtin.exit) == 0)
	{
		exitcmd(cmd, new_line);
		return (1);
	}
	return (0);
}
/**
* exitcmd - handles the exit command
* @cmd: tokenized command
* @newline: input read from stdin
*
* Return: no return
*/
void exitcmd(char **cmd, char *newline)
{
	free(newline);
	free_buff(cmd);
	exit(0);
}
