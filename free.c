#include "simple_shell.h"
/**
 * free_list - freeing alias list
 * @head: beginning of list
 * Return: 0 on success
 */
int free_list(list_t *head)
{
	list *another;

	while (head)
	{
		another = head->another;
		free(head->s);
		free(head->count);
		free(head);
		head = another;
	}
	return (0);
}
