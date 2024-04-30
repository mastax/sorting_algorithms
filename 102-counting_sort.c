#include "sort.h"
#include <stdlib.h>

/**
 * ar_max - array max
 * @array: array
 * @size: size of the array
 * Return: max
 */
int ar_max(int *array, size_t size)
{
	int max;
	size_t idx;

	max = array[0];
	for (idx = 1; idx < size; idx++)
		if (array[idx] > max)
			max = array[idx];
	return (max);
}

/**
 * counting_sort - sorts an Array with the counting sort algorithm
 * @array: array to sort,
 * @size: size of the array,
 */
void counting_sort(int *array, size_t size)
{
	int *ar, *o_ar, mx, nm;
	size_t idx;

	if (size < 2 || !array)
		return;
	mx = ar_max(array, size);

	ar = malloc(sizeof(size_t) * (mx + 1));
	o_ar = malloc(sizeof(int) * size);

	for (idx = 0; (int)idx <= mx; idx++)
		ar[idx] = 0;
	for (idx = 0; idx < size; idx++)
	{
		nm = array[idx];
		ar[nm] += 1;
	}
	for (idx = 1; (int)idx <= mx; idx++)
		ar[idx] += ar[idx - 1];
	print_array(ar, mx + 1);
	for (idx = 0; idx < size; idx++)
	{
		o_ar[ar[array[idx]] - 1] = array[idx];
		ar[array[idx]]--;
	}
	for (idx = 0; idx < size; idx++)
		array[idx] = o_ar[idx];

	free(o_ar);
	free(ar);
}