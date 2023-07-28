#include "simple_shell.h"
/**
* findpath - finds the path from the global enviroment
* Return: NULL if path is not found or path if path is found.
*/
char *findpath(void)
{
	int i;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && i < 5)
			{
				path++;
				i++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}
/**
* testpath - checks whether path is valid
* @path: tokenized path
* @cd: user entered command
*
* Return: path appended with command on success
* NULL on failure
*/
char *testpath(char **path, char *cd)
{
	int x = 0;
	char *output;

	while (path[i])
	{
		output = _append_path(path[i], cd);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		x++;
	}
	return (NULL);
}
