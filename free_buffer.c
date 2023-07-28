#include "simple_shell.h"

/**
* free_buff - frees buffers
* @buffer: buffer to be freed
*
* Return: no return
*/
void free_buff(char **buffer)
{
	int j = 0;

	if (!buffer || buffer == NULL)
		return;
	while (buffer[j])
	{
		free(buffer[j]);
		j++;
	}
	free(buffer);
}
