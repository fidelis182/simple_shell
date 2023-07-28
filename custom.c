#include "simple_shell.h"

/**
 * generate_error - prints custom error message to stderr
 * @args: arguments array
 * @error_value: error value
 * Return: error
 */
int generate_error(char **args, int error_value)
{
	char *err;

	switch (error_value)
	{
	case -1:
		err = biultin_env_error(args);
		break;
	case 1:
		err = biultin_alias_error(args);
		break;
	case 2:
		if (*(args[0]) == 'e')
			err = exit_error(++args);
		else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
			err = syntax_error(args);
		else
			err = command_error(args);
		break;
	case 126:
		err = denied_permissionargs);
		break;
	case 127:
		err = command_error(args);
		break;
	}
	write(STDERR_FILENO, err, _strlen(err));

	if (err)
		free(err);
	return (error_value);

}

/**
 * _itoa - Converts an integer to a string.
 * @num: number passed
 * Return: error string.
 */
char *_itoa(int num)
{
	char *buff;
	int length = num_length(num);
	unsigned int num1;

	buff = malloc(sizeof(char) * (length + 1));
	if (!buff)
		return (NULL);

	buff[length] = '\0';

	if (num < 0)
	{
		num1 = num * -1;
		buff[0] = '-';
	}
	else
	{
		num1 = num;
	}

	length--;
	do {
		buff[length] = (num1 % 10) + '0';
		num1 /= 10;
		len--;
	} while (num1 > 0);

	return (buff);
}

/**
 * num_length - Counts the digit length of a number.
 * @num: number to measure
 * Return: The number length
 */
int num_length(int num)
{
	unsigned int num1;
	int length = 1;

	if (num < 0)
	{
		length++;
		num1 = num * -1;
	}
	else
	{
		num1 = num;
	}
	while (num1 > 9)
	{
		length++;
		num1 /= 10;
	}

	return (length);
}
