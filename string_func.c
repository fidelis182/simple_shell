#include "simple_shell.h"

/**
 * *_strcpy - copy strings
 * @dest: - destination to be copied to
 * @src: - srouce string
 * Return: return dest.
 */
char *_strcpy(char *dest, char *src)
{
	int c;

	for (c = 0; src[c] != '\0'; c++)
	{
		dest[c] = src[c];
	}
	dest[c++] = '\0';
	return (dest);
}
/**
 * _strtok - this tokenizes the string inputed
 * @line: the string passed
 * @deli: the delimiter
 * Return: pointer cointaining the tokenised strings
 */
char **_strtok(char *line, char *deli)
{
	char **ptr;
	int index = 0, token, tok, let, letter;

	token = counting_token(line, deli);
	if (token == 0)
		return (NULL);
	ptr = malloc(sizeof(char *) * (token + 2));
	if (!ptr)
		return (NULL);

	for (let = 0; let < token; let++)
	{
		while (line[index] == *deli)
			ind++;

		letter = token_length(line + index, deli);
		ptr[let] = malloc(sizeof(char) * (letter + 1));
		if (!ptr[let])
		{
			for (index-= 1; index >= 0; index--)
				free(ptr[index]);
			free(ptr);
			return (NULL);
		}

		for (tok = 0; tok < letter; tok++)
		{
			ptr[let][tok] = line[index];
			index++;
		}
		ptr[let][tok] = '\0';
	}
	ptr[let] = NULL;
	ptr[let + 1] = NULL;
	return (ptr);
}
/**
 * _strchr - checking characters
 * @src: string to be compared
 * @j: character to be found
 * Return: Always 0 (Success)
 */
char *_strchr(char *src, char j)
{
	int i = 0;

	while (src[i] >= '\0')
	{
		if (src[i] == j)
		{
			return (&src[i]);
		}
	i++;
	}
	return (0);
}

/**
 * _strspn - find the length of prefix string
 * @stng: full string
 * @string: string to check
 * Return: return i
 */

unsigned int _strspn(char *stng, char *string)
{
	unsigned int a, c = 0;

	while (*stng)
	{
		for (a = 0; string[a]; a++)
		{
			if (*stng == string[a])
		{
			c++;
			break;
		}
			else if (string[a + 1] == '\0')
				return (c);
		}
		stng++;
	}
	return (c);
}
