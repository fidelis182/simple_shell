#include "simple_shell.h"
/**
 * free_list - freeing alias list
 * @head: beginning of list
 * Return: 0 on success
 */
int free_list(list *head)
{
	list *another;

	while (head)
	{
		another = head->another;
		free(head->s);
		free(head->another);
		free(head);
		head = another;
	}
	return (0);
}
