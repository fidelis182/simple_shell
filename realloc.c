#include "simple_shell.h"
/**
 * realloc - reallocating memory
 * @p: pointer to former memory
 * @former: size of former memory
 * @nw: size of new memory
 * Return: memory reallocated
 */
void *realloc(void *p, unsigned int former, unsigned int nw)
{
	void *memory;
	char *p_cpy, *fill;
	unsigned int index;

	if (nw == former)
		return (p);

	if (p == NULL)
	{
		memory = malloc(nw);
		if (memory == NULL)
			return (NULL);

		return (memory);
	}

	if (nw == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}
	p_cpy = p;
	memory = malloc(sizeof(*p_cpy) * nw);
	if (memory == NULL)
	{
		free(p);
		return (NULL);
	}
	fill = memory;
	index = 0;

	while (index < former && index < nw)
	{
		fill[index] = *p_cpy++;
		index++;
	}
	free(p);
	return (memory);
}

/**
 * _get_line - reads an input string from a stream
 * @ptr: stores the input string
 * @num: size of ptr
 * @stream: file to read
 * Return: rep on success
 */
ssize_t _get_line(char **ptr, size_t *num, FILE *stream)
{
	static ssize_t pass;
	ssize_t rep;
	char *buffer, prt = 'x';
	int p;

	if (pass == 0)
		fflush(stream);
	else
		return (-1);
	pass = 0;
	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	for (; prt != '\n'; pass++)
	{
		p = read(STDIN_FILENO, &prt, 1);
		if (p == -1 || (p == 0 && pass == 0))
		{
			free(buffer);
			return (-1);
		}
		if (p == 0 && pass != 0)
		{
			pass++;
			break;
		}
		if (pass >= 120)
		{
			buffer = realloc(buffer, pass, pass + 1);
		}
		buffer[pass] = prt;
	}
	buffer[pass] = '\0';
	assigning(ptr, num, buffer, pass);
	rep = pass;

	if (p != 0)
		pass = 0;
	return (rep);
}

/**
 * reassigning - reassigns prt for getline
 * @ptr: an input string
 * @num: size of ptr
 * @buff: buffer to assign the string to
 * @pass: size of buffer
 */
void reassigning(char **ptr, size_t *num, char *buffer, size_t pass)
{
	if (*ptr == NULL)
	{
		if (pass > 120)
			*num = pass;
		else
			*num = 120;
		*ptr = buffer;
	}
	else if (*num < pass)
	{
		if (pass > 120)
			*num = pass;
		else
			*num = 120;
		*ptr = buffer;
	}
	else
	{
		_strcpy(*ptr, buffer);
		free(buffer);
	}
}
