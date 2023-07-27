#include "simple_shell.h"

/**
 *free_env - freeing the environment
 */
void free_env(void)
{
	int index = 0;

	while (environ[index])
	{
		free(environ[index]);
		ind++;
	}
	free(environ);
}
/**
 * get_env - getting the envir variable
 * @indx: environment variable to get
 * Return: pointer to envir variable
 */
char **get_env(char *index)
{
	int ind = 0, len;

	len = _strlen(index);

	while (environ[ind])
	{
		if (_strncmp(index, environ[ind], len) == 0)
			return (&environ[ind]);
		ind++;
	}
	return (NULL);
}
/**
 * copy_env - copying environment
 * Return: new environment on success
 */
char **copy_env(void)
{
	int index;
	char **Nenvir;
	size_t length = 0;

	while (environ[length])
	{
		length++;
	}

	Nenvir = malloc(sizeof(char *) * (length + 1));
	if (!Nenvir)
		return (NULL);
	index = 0;

	while (environ[index])
	{
		Nenvir[index] = malloc(_strlen(environ[index]) + 1);
		if (!Nenvir[index])
		{
			for (index--; index >= 0; index--)
				free(Nenvir[ind]);
			free(Nenvir);
			return (NULL);
		}
		_strcpy(Nenvir[index], environ[index]);
		index++;
	}
	Nenvir[index] = NULL;
	return (Nenvir);
}
