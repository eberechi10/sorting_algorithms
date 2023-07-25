#include "sort.h"
#include <stdio.h>

/**
 * swap_func - function to swap two nodes in list.
 *
 * @list: pointer to list.
 * @n1: first node.
 * @n2: second node.
 *
 * Return: return nothing.
 */
void swap_func(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (n1->prev)
		n1->prev->next = n2;

	else
		*list = n2;

	if (n2->next)
		n2->next->prev = n1;

	n1->next = n2->next;
	n2->prev = n1->prev;

	n1->prev = n2;
	n2->next = n1;

	print_list(*list);
}

/**
 * cocktail_sort_list - function to sort list in ascending order
 *                      using Cocktail Shaker Sort algorithm.
 *
 * @list: pointer of list.
 *
 * Return: return nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	int n_swapped;
	listint_t *left, *right, *end;

	if (list == NULL || *list == NULL)
		return;
	end = NULL;
	do {
		n_swapped = 0;
		left = *list;

		while (left->next != end)
		{
			right = left->next;

			if (left->n > right->n)
			{
				swap_func(list, left, right);
				n_swapped = 1;
			} else
				left = left->next;
		}
		end = left;

		if (!n_swapped)
			break;

		n_swapped = 0;
		right = end;
		while (right->prev != NULL)
		{
			left = right->prev;
			if (right->n < left->n)
			{
				swap_func(list, left, right);
				n_swapped = 1;
			} else
				right = right->prev;
		}
	} while (n_swapped);
}
