#include "simple_shell.h"

/**
 * counting_token - counting the number of token in a string
 * @s1: strings with the token
 * @delimit: delimiter to separate each token
 * Return: tokens
 */
int counting_token(char *s1, char *delimit)
{
	int index, token, len = 0;

	for (index = 0; *(s1 + index); index++)
	{
		len++;
	}

	index = 0;
	token = 0;

	while (index < len)
	{
		if (*(s1 + index) != *delimit)
		{
			token++;
			index += token_len(s1 + index, delimit);
		}
		index++;
	}
	return (token);
}

/**
 * token_length - length of the token on getting to a delimiter
 * @s1: strings to be counted to reach a dlimiter
 * @delimit: delimiter to truncate a string
 * Return: length of the token in a string
 */
int token_length(char *s1, char *delimit)
{
	int index, len = 0;

	for (index = 0; (*(s1 + index) && *(s1 + index) != *delimit); index++)
	{
		len++;
	}
	return (len);
}
