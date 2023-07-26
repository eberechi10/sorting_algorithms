#include "sort.h"

/**
 * take_func - function to get value in array integers.
 *
 * @array: the array.
 * @size: size of array.
 *
 * Return: integer in the array.
 */
int take_func(int *array, int size)
{
	int i, max_elm = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_elm)
			max_elm = array[i];
	}

	return (max_elm);
}

/**
 * counting_sort - function for sorting integers in ascending order
 *                 using the counting sort algorithm.
 *
 * @array: the array.
 * @size: size of array.
 *
 * Return: the array list.
 */
void counting_sort(int *array, size_t size)
{
	int *arr_count, *arr_sorted, max_elm, i;

	if (array == NULL || size < 2)
		return;

	max_elm = take_func(array, size);
	arr_count = malloc(sizeof(int) * (max_elm + 1));
	arr_sorted = malloc(sizeof(int) * size);

	if (arr_count == NULL || arr_sorted == NULL)
	{
		free(arr_count);
		free(arr_sorted);
		return;
	}

	for (i = 0; i <= max_elm; i++)
		arr_count[i] = 0;

	for (i = 0; i < (int)size; i++)
		arr_count[array[i]]++;

	for (i = 1; i <= max_elm; i++)
		arr_count[i] += arr_count[i - 1];

	print_array(arr_count, max_elm + 1);

	for (i = 0; i < (int)size; i++)
	{
		arr_sorted[arr_count[array[i]] - 1] = array[i];
		arr_count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = arr_sorted[i];

	free(arr_count);
	free(arr_sorted);

}
