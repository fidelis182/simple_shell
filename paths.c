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

	while (path[x])
	{
		output = _append_path(path[x], cd);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		x++;
	}
	return (NULL);
}

/**
* _append_path - adds path to command
* @path: path of command
* @cmd: user entered command
*
* Return: buffer containing command with path on success
* NULL on failure
*/
char *_append_path(char *path, char *cmd)
{
	char *buff;
	size_t i = 0, j = 0;

	if (cmd == 0)
		cmd = "";

	if (path == 0)
		path = "";

	buff = malloc(sizeof(char) * (_strlen(path) + _strlen(cmd) + 2));
	if (!buff)
		return (NULL);

	while (path[i])
	{
		buff[i] = path[i];
		i++;
	}

	if (path[i - 1] != '/')
	{
		buff[i] = '/';
		i++;
	}
	while (cmd[j])
	{
		buff[i + j] = cmd[j];
		j++;
	}
	buff[i + j] = '\0';
	return (buff);
}
