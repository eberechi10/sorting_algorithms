#include "sort.h"

/**
 * swap_func - function for swapping two integers.
 *
 * @a: first integer.
 * @b: second integer.
 */
void swap_func(int *a, int *b)
{
	int elm;

	elm = *a;
	*a = *b;
	*b = elm;
}


/**
 * shell_sort - sorting in ascending order using the shell sort
 *               using Knuth interval sequence.
 *
 * @array: the array.
 * @size: size of array.
 *
 * Return: the sorted list.
 */
void shell_sort(int *array, size_t size)
{

	size_t idx, swap, p;

	if (array == NULL || size < 2)
		return;

	for (swap = 1; swap < (size / 3);)
		swap = swap * 3 + 1;

	for (; swap >= 1; swap /= 3)
	{

		for (idx = swap; idx < size; idx++)
		{
			p = idx;

			while (p >= swap && array[p - swap] > array[p])
			{
				swap_func(array + p, array + (p - swap));
				p -= swap;
			}
		}
		print_array(array, size);
	}
}
