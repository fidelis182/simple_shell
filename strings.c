#include "simple_shell.h"

/**
* _strlen - returns the length of a string
* @str: string passed
*
* Return: returns length of string passed
*/
int _strlen(char *str)
{
	int counter = 0;

	while (*str != '\0')
	{
		counter++;
		str++;
	}
	return (counter);
}
/**
* _strchr - locates a character in a string
* @str: string to be checked
* @ctr: character to be located
*
* Return: returns pointer to first occurence of character
* or NULL if character not found
*/
char *_strchr(char *str, char ctr)
{
	while (*str)
	{
		if (*str == ctr)
			return (str);
		str++;
	}
	if (!ctr)
		return (str);
	return (NULL);
}
/**
* _strdup - dupicates string
* @str: to be duplicated
*
* Return: pointer to duplicate string
*/
char *_strdup(char *str)
{
	char *pt;
	int i, length;

	if (str == NULL)
		return (NULL);

	length = _strlen(str);

	pt = malloc(sizeof(char) * (length + 1));
	if (!pt)
		return (NULL);
	for (i = 0; *str != '\0'; str++, i++)
		pt[i] = str[0];

	pt[i++] = '\0';
	return (pt);
}
/**
* _strncmp - compares two strings up to n bytes
* @str1: compared to s2
* @sttr2: compared to s1
* @n: number of bytes
*
* Return: difference between str1 and str2
*/
int _strncmp(char *str1, char *str2, int n)
{
	int i;

	for (i = 0; str1[i] && str2[i] && i < n; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}
/**
* _strcmp - compares two strings
* @str1: compared to s2;
* @str2: compared to s1;
*
* Return: returns difference between strings
*/
int _strcmp(char *str1, char *str2)
{
	int i = 0, output;

	while (*(str1 + i) == *(str2 + i) && *(str1 + i) != '\0')
		i++;

	output = (*(str1 + i) - *(str2 + i));

	return (output);
}

