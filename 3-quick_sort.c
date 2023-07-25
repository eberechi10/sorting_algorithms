#include "sort.h"

void rec_quick_sort(int *array, size_t size, int *array_s, size_t size_s);

/**
 * quick_sort - function for quick sorting Algorithm.
 *
 * @array: array to sort.
 * @size: size of array sort..
 *
 * Return: the sorted list.
 */

void quick_sort(int *array, size_t size)
{
	rec_quick_sort(array, size, array, size);
}

/**
 * rec_quick_sort - function for recursive quick sort Algorithm.
 *
 * @array: subarray in the recursive.
 * @size: size of subarray.
 *
 * @array_s: Pointer of the first array.
 * @size_s: Size of the firstarray.
 *
 * Return: te sorted list.
 */

void rec_quick_sort(int *array, size_t size, int *array_s, size_t size_s)
{
	size_t cursor, idx_s, x_pivot;
	int a_size, cage, b_size;

	if (array == NULL || size < 2)
		return;

	x_pivot = size - 1;
	cursor = 0;
	idx_s = -1;

	while (cursor <= x_pivot)
	{
		if (array[cursor] <= array[x_pivot])
		{
			idx_s++;

			if (cursor > idx_s)
			{
				cage = array[cursor];
				array[cursor] = array[idx_s];
				array[idx_s] = cage;
				print_array(array_s, size_s);
			}
		}
		cursor++;
	}

	a_size = idx_s;
	b_size = size - idx_s - 1;

	rec_quick_sort(array, a_size, array_s, size_s);
	rec_quick_sort(idx_s + array + 1, b_size, array_s, size_s);
}
