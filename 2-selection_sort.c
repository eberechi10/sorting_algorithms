#include "sort.h"

/**
 * swap_func - function for swapping two integers.
 *
 * @a: integer number one.
 * @b: integer number two.
 */
void swap_func(int *a, int *b)
{
	int elm;

	elm = *a;
	*a = *b;
	*b = elm;
}

/**
 * selection_sort - sort integers in ascending order by selection
 *
 * @array: the integers.
 * @size: integer size
 *
 * Return: the sorted list.
 */
void selection_sort(int *array, size_t size)
{
	int *node;
	size_t idx, p;

	if (array == NULL || size < 2)
		return;

	for (idx = 0; idx < size - 1; idx++)
	{
		node = array + idx;

		for (p = idx + 1; p < size; p++)
			node = (array[p] < *node) ? (array + p) : node;

		if ((array + idx) != node)
		{
			swap_func(array + idx, node);

			print_array(array, size);
		}
	}
}
