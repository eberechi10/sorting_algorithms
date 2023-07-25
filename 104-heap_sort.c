#include "sort.h"


void swap_func(int *n1, int *n2);
void max_heapify(int *array, size_t size, size_t index, size_t end);
void heap_sort(int *array, size_t size);


/**
 * swap_func - function for swapping two integers.
 *
 * @n1: first integer.
 * @n2: second integer.
 */
void swap_func(int *n1, int *n2)
{
	int elm;

	elm = *n1;
	*n1 = *n2;
	*n2 = elm;
}


/**
 * max_elm -  binary heap tree function
 *
 * @array: array of integer.
 * @size: size of array.
 *
 * @index: index of the base.
 * @end: end node of tree.
 *
 * Return: the complete binary tree.
 */
void max_elm(int *array, size_t size, size_t index, size_t end)
{
	size_t large, right, left;

	left = 2 * end + 1;
	right = 2 * end + 2;
	large = end;

	if (left < index && array[left] > array[large])
		large = left;

	if (right < index && array[right] > array[large])
		large = right;

	if (large != end)
	{
		swap_func(array + end, array + large);
		print_array(array, size);

		max_elm(array, size, index, large);
	}
}


/**
 * heap_sort - function for sorting integers in ascending
 *             order using the heap sort algorithm.
 *
 * @array: the array.
 * @size: size of array.
 *
 * Return: the sorted array.
 */
void heap_sort(int *array, size_t size)
{
	int idx;

	if (array == NULL || size < 2)
		return;

	for (idx = (size / 2) - 1; idx >= 0; idx--)
		max_elm(array, size, size, idx);

	for (idx = size - 1; idx > 0; idx--)
	{
		swap_func(array, array + idx);
		print_array(array, size);

		max_elm(array, size, idx, 0);
	}
}
