#include "sort.h"


int max_elm(int *array, int size);

void counting_sort_r(int *array, size_t size, int signif, int *buf);
void radix_sort(int *array, size_t size);


/**
 * max_elm - function for max value in integer array.
 *
 * @array: the array.
 * @size: size of array.
 *
 * Return: max integer in array.
 */
int max_elm(int *array, int size)
{
	int arr_max, idx;

	for (arr_max = array[0], idx = 1; idx < size; idx++)
	{
		if (array[idx] > arr_max)

			arr_max = array[idx];
	}

	return (arr_max);
}


/**
 * counting_sort_r - function for sorting significant digit in ascending
 *                       order using the counting.
 *
 * @array: the array
 * @size: size of array.
 *
 * @signif: significant digit.
 * @buf: buffer that stores the array.
 *
 *Return: Nothing.
 */
void counting_sort_r(int *array, size_t size, int signif, int *buf)
{
	int total[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t idx;


	for (idx = 0; idx < size; idx++)

		total[(array[idx] / signif) % 10] += 1;

	for (idx = 0; idx < 10; idx++)
		total[idx] += total[idx - 1];

	for (idx = size - 1; (int)idx >= 0; idx--)
	{
		buf[total[(array[idx] / signif) % 10] - 1] = array[idx];
		total[(array[idx] / signif) % 10] -= 1;
	}
	for (idx = 0; idx < size; idx++)

		array[idx] = buf[idx];
}


/**
 * radix_sort - function to sort array integers in ascending order
 *              using the radix sort algorithm.
 *
 * @array: the array.
 * @size: size of array.
 *
 * Description: Implementing LSD radix sort algorithm. Prints
 *              on each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int arr_max, signif, *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);

	if (buf == NULL)
		return;

	arr_max = max_elm(array, size);
	for (signif = 1; arr_max / signif > 0; signif *= 10)
	{
		counting_sort_r(array, size, signif, buf);
		print_array(array, size);
	}
	free(buf);
}
