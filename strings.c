#include "simple_shell.h"
/**
 * strlen - prints the length of the array
 * @c: a pointer the character we want to get it`s length
 *
 * Return: length 'b'
 */
int str_len(char *c)
{
	int b = 0;

	while (*c != '\0')
	{
		b++;
		c++;
	}
	return (b);
}

/**
 * _strcmp - compare two strings
 * @string1: the first string
 * @string2: the second string
 *
 * Return: returns value.
 */

int _strcmp(char *string1, char *string2)
{
	int c = 0;

	while (string1[c] != '\0' && string2[c] != '\0')
	{
		if (string1[c] != string2[c])
		{
			return (string1[c] - string2[c]);
		}
		c++;
	}
		return (0);
}

/**
 * *_strncat - to concatenate two strings
 * @dest: the destination string
 * @src: the source string
 * @n: number of source byte
 * Return: return destination string
 */

char *_strncat(char *dest, char *src, int n)
{
	int c = 0;
	int len = 0;

	while (dest[len] != '\0')
	{
		len++;
	}

	for (c = 0; c < n && src[c] != '\0'; c++)
	{
		dest[len + c] = src[c];
	}

	return (dest);
}

/**
 * *_strcat - to concatenate two strings
 * @dest: destination string
 * @src: source string
 * Return: return destination string
 */

char *_strcat(char *dest, char *src)
{
	int c = 0;
	int len = 0;

	while (dest[tlen] != '\0')
	{
		len++;
	}

	for (c = 0; src[c] != '\0'; c++)
	{
		dest[len + c] = src[c];
	}
	dest[len + c] = '\0';
	return (dest);
}

/**
 * _strncmp - compare two strings
 * @string1: the first string
 * @string2: the second string
 * @n: number of strings to be compared
 * Return: returns value.
 */
int _strncmp(char *string1, char *string2, size_t n)
{
	size_t c = 0;

	while (string1[c] != '\0' && string2[c] != '\0')
	{
		if (string1[c] > string2[c])
		{
			return (string1[c] - string2[c]);
		}
		else if (string1[c] < string2[c])
		{
			return (string1[c] - string2[c]);
		}
		c++;
	}
	if (c == n)
		return (0);
	else
		return (-1);
}
