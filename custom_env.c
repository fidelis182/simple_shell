#include "simple_shell.h"

/**
* printenv - prints the environment string to stdout
*
* Return: 0
*/
void printenv(void)
{
	int i = 0;
	char **env = environ;

	while (env[i])
	{
		write(STDOUT_FILENO, (const void *)env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
