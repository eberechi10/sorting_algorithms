#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * me - function to merge two sorted sub-arrays into an array.
 *
 * @array: the array.
 * @size: size of array.
 *
 * @left: left sub-array.
 * @l_s: size of left sub-array.
 *
 * @right: the right sub-array.
 * @r_s: size of right sub-array.
 *
 * Return: Nothing.
 */
void me(int *array, size_t size, int *left, size_t l_s, int *right, size_t r_s)
{

	size_t i = 0, j = 0, p = 0;

	int *elm = malloc(size * sizeof(int));

	if (elm == NULL)
	{
	printf("Memory allocation error.\n");
		return;
	}

	while (i < l_s && j < r_s)
	{
	if (left[i] <= right[j])
		elm[p++] = left[i++];

	else
		elm[p++] = right[j++];
	}

	while (i < l_s)
		elm[p++] = left[i++];

	while (j < r_s)
		elm[p++] = right[j++];

	for (i = 0; i < size; i++)
		array[i] = elm[i];

	free(elm);
}

/**
 * merge_sort - function for sorting array integers in ascending order
 *              using Merge sort algorithm.
 *
 * @array: the array.
 * @size: size of array.
 *
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t mid, r_size, l_size;

	if (array == NULL || size <= 1)
	return;

	mid = size / 2;
	l_size = mid;
	r_size = size - mid;

	left = array;
	right = array + mid;

	merge_sort(left, l_size);
	merge_sort(right, r_size);
	me(array, size, left, l_size, right, r_size);
}
