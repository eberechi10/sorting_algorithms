#include "sort.h"

/**
 * insertion_sort_list - function for insertion sorting.
 *
 * @list: linked list to sort.
 *
 * Return: the sorted list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *n_sort, *for_sort;

	if (!list || !(*list) || !(*list)->next)
		return;

	n_sort = (*list)->next;

	while (n_sort)
	{
		for_sort = n_sort;
		n_sort = n_sort->next;

		while (for_sort->prev && (for_sort->prev->n > for_sort->n))
		{
			for_sort->prev->next = for_sort->next;
			if (for_sort->next)
				for_sort->next->prev = for_sort->prev;

			for_sort->next = for_sort->prev;

			for_sort->prev = for_sort->prev->prev;

			for_sort->next->prev = for_sort;

			if (for_sort->prev)
				for_sort->prev->next = for_sort;
			else
				*list = for_sort;
		/*print the sorted list */
			print_list(*list);
		}
	}
}
