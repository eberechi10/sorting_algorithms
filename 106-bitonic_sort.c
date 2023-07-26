#include "sort.h"


void swap_func(int *a, int *b);
void join_bitonic(int *array, size_t size, size_t begi, size_t sq, char gon);
void bitonic_seq(int *array, size_t size, size_t begi, size_t sq, char gon);
void bitonic_sort(int *array, size_t size);


/**
 * swap_func - function to swap two integers.
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
 * sq_bitonic - function to create bitonic sequence.
 *
 * @array: the array
 * @size: size of array.
 *
 * @begi: index bitonic sequence.
 * @sq: size bitonic sequence.
 *
 * @gon: direction bitonic sequence sort.
 */
void sq_bitonic(int *array, size_t size, size_t begi, size_t sq, char gon)
{
	size_t nod;
	char *str;

	nod = sq / 2;
	str = (gon == UP) ? "UP" : "DOWN";

	if (sq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sq, size, str);
		print_array(array + begi, sq);

		sq_bitonic(array, size, begi, nod, UP);
		sq_bitonic(array, size, begi + nod, nod, DOWN);

		join_bitonic(array, size, begi, sq, gon);

		printf("Result [%lu/%lu] (%s):\n", sq, size, str);
		print_array(array + begi, sq);
	}
}



/**
 * join_bitonic - function to sort sequence in array integers.
 *
 * @array: the array
 * @size: size of array.
 *
 * @begi: index of sequence in array.
 * @sq: size of sequence.
 *
 * @dir: direction of the sort.
 */
void join_bitonic(int *array, size_t size, size_t begi, size_t sq, char dir)
{
	size_t idx, gon;

	gon = sq / 2;

	if (sq > 1)
	{
		for (idx = begi; idx < begi + gon; idx++)
		{
			if ((dir == UP && array[idx] > array[idx + gon]) ||
			    (dir == DOWN && array[idx] < array[idx + gon]))

				swap_func(array + idx, array + idx + gon);
		}
		join_bitonic(array, size, begi, gon, dir);
		join_bitonic(array, size, begi + gon, gon, dir);
	}
}



/**
 * bitonic_sort - function to sort array integers in ascending order
 *                using the bitonic sort.
 *
 * @array: the array.
 * @size: size of array.
 *
 * Description: it prints array after each swap.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sq_bitonic(array, size, 0, size, UP);
}
