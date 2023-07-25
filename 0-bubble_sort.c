#include "sort.h"


/**
 * swap_func - function to swap two integers.
 *
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 *
 * Return: the swapped integer.
 */
void swap_func(int *a, int *b)
{
	int elm;

	elm = *a;
	*a = *b;
	*b = elm;
}


/**
 * bubble_sort - functoin to sort integers in ascending order.
 *
 * @array: the array to sort.
 * @size: th size of array.
 *
 * Return: the sorted array..
 */
void bubble_sort(int *array, size_t size)
{
	size_t idx, nlen;
	bool swapped = false;

	nlen = size;

	if (array == NULL || size < 2)
		return;

	while (swapped == false)
	{
		swapped = true;
		for (idx = 0; idx < nlen - 1; idx++)
		{
			if (array[idx] > array[idx + 1])
			{
				swap_func(array + idx, array + idx + 1);
				print_array(array, size);

				swapped = false;
			}
		}
		nlen--;
	}
}
