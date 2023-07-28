#include "simple_shell.h"

/**
 * _split_line- splits a line column
 * @current: current char
 * @next: next char
 * @new_line: new_line
 * @old_line: old line
 * @i: input int
 * @j: input int
 * Return: result
 */
int _split_line(size_t i, size_t j, char current,
		char next, char *old_line, char *new_line)
{
	char prev;

	prev = old_line[i - 1];
	if (current == ';')
	{
		return (split_column(j, prev, next, new_line));
	}
	else if (current == '&')
	{
		return (split_and(j, prev, next, new_line));
	}
	else if (current == '|')
	{
		return (split_pipe(j, prev, next, new_line));
	}
	return (1);
}

/**
 * split_column - splits a line column
 * @next: next char
 * @old_line: old line
 * @new_line: new line
 * @i: input int
 * @j: input int
 * Return: result
 */
int split_column(size_t i, size_t j, char next,
		char *old_line, char *new_line)
{
	if (i != 0 && old_line[i - 1] != ' ')
		new_line[j++] = ' ';
	new_line[j++] = ';';
	if (next != ' ' && next != ';')
		new_line[j++] = ' ';
	return (0);
}
/**
 * splitpipe - splits a line pipe
 * @prev: prev char
 * @next: next char
 * @new_line: new line
 * @j: input int
 * Return: result
 */
int splitpipe(size_t j, char prev, char next, char *new_line)
{
	if (next == '|' && prev != ' ')
		new_line[j++]  = ' ';
	else if (prev == '|' && next != ' ')
	{
		new_line[j++] = '|';
		new_line[j++] = ' ';
		return (0);
	}
	return (1);
}
/**
 * split_and - splits a line and
 * @prev: prev char
 * @next: next char
 * @new_line: new line
 * @j: input int
 * Return: result
 */
int split_and(size_t j, char prev, char next, char *new_line)
{
	if (next == '&' && prev != ' ')
		new_line[j++] = ' ';
	else if (prev == '&' && next != ' ')
	{
		new_line[j++] = '&';
		new_line[j++] = ' ';
		return (0);
	}
	return (1);
}
/**
 * split_line_column - splits a line column
 * @prev: prev char
 * @next: next char
 * @new_line: new line
 * @j: input int
 * Return: result
 */
int split_line_column(size_t j, char prev, char next, char *new_line)
{
	if (next == ';' && prev != ' ' && prev != ';')
	{
		new_line[j++] = ' ';
		new_line[j++] = ';';
		return (0);
	}
	else if (prev == ';' && next != ' ')
	{
		new_line[j++] = ';';
		new_line[j++] = ' ';
		return (0);
	}
	if (prev != ' ')
		new_line[j++] = ' ';
	new_line[j++] = ';';
	if (next != ' ')
		new_line[j++] = ' ';
	return (0);
}
