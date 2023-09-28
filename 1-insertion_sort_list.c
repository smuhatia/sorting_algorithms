#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: doubly linked list to be sorted
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		prev = current->prev;

		while (prev && current->n < prev->n)
		{
			prev->next = current->next;

			if (current->next)
				current->next->prev = prev;

			current->prev = prev->prev;
			current->next = prev;

			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;

			prev->prev = current;
			prev = current->prev;

			print_list(*list);
		}
		current = current->next;
	}
}

