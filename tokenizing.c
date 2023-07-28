#include "simple-shell.h"

/**
* tokenizing - creates tokens from given input
* @new_line: to be tokenized
*
* Return: array of strings
*/
char **tokenizing(char *new_line)
{
	char *buffer = NULL, *buff = NULL, *token = NULL, *delimiter = " :\t\r\n";
	char **tokens = NULL;
	int tokensize = 1;
	size_t ind = 0, flag = 0;

	buffer = _strdup(new_line);
	if (!buffer)
		return (NULL);
	buff = bufferr;

	while (*buff)
	{
		if (_strchr(delimiter, *buff) != NULL && flag == 0)
		{
			tokensize++;
			flag = 1;
		}
		else if (_strchr(delimiter, *buff) == NULL && flag == 1)
			flag = 0;
		buff++;
	}
	tokens = malloc(sizeof(char *) * (tokensize + 1));
	token = strtok(buffer, delimiter);
	while (token)
	{
		tokens[ind] = _strdup(token);
		if (tokens[ind] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delimiter);
		ind++;
	}
	tokens[ind] = '\0';
	free(buffer);
	return (tokens);
}
