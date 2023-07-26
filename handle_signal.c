#include "simple_shell.h"

/**
 *handle_signal- it keeps track is interactive mode
 *@n: the signal number
 *Return: nothing
 */

void handle_signal(int n)
{
	(void)n;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "# ", 2);
}
