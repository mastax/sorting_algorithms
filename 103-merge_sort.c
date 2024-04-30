#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * ft_print_left_right - print left and right partitions
 * @arr: array
 * @sze: size of second array
 * @frst: initial position
 * @mid: middle position
 */
void ft_print_left_right(int *arr, int sze, int frst, int mid)
{
	int k;

	printf("Merging...\n");
	printf("[left]: ");
	k = frst;
	while (k < mid)
	{
		if (k != mid - 1)
			printf("%d, ", arr[k]);
		else
			printf("%d\n", arr[k]);
		k++;
	}

	printf("[right]: ");
	k = mid;
	while (k < sze)
	{
		if (k < sze - 1)
			printf("%d, ", arr[k]);
		else
			printf("%d\n", arr[k]);
		k++;
	}
}

/**
 * ft_merge - merge the values in the position of array,
 * @arr: first array,
 * @sze: size of second array,
 * @cpy: copy of array,
 * @frst: initial position,
 * @mid: middle position,
 * first one of the second array,
 */
void ft_merge(int *arr, int sze, int frst, int mid, int *cpy)
{
	int x, y, z;

	print_left_right(arr, sze, frst, mid);

	x = frst;
	y = mid;

	printf("[Done]: ");
	z = frst;
	while (z < sze)
	{
		if (x < mid && (y >= sze || arr[x] <= arr[y]))
		{
			cpy[z] = arr[x];
			x++;
		}
		else
		{
			cpy[z] = arr[y];
			y++;
		}
		if (z < sze - 1)
			printf("%d, ", cpy[z]);
		else
			printf("%d\n", cpy[z]);
		z++;
	}
}
/**
 * ft_mergeSort - array separator,
 * @cpy: copy of array,
 * @frst: initial position,
 * @sze: size of the original  array,
 * @arr: the original array,
 */
void ft_mergeSort(int *cpy, int frst, int sze, int *arr)
{
	int mid;

	if (sze - frst < 2)
		return;

	mid = (sze + frst) / 2;

	mergeSort(arr, frst, mid, cpy);
	mergeSort(arr, mid, sze, cpy);

	merge(cpy, sze, frst, mid, arr);
}
/**
 * ft_copy_array - copy array of int,
 * @arra: array src,
 * @cpy: array dest
 * @sze : array size,
 */
void ft_copy_array(int *arra, int *cpy, int sze)
{
	int idx;

	for (idx = 0; idx < (int)sze; idx++)
		cpy[idx] = arra[idx];
}

/**
 * merge_sort - create partition and copy
 * @array: array
 * @size : array size
 */
void merge_sort(int *array, size_t size)
{
	int *cpi;

	cpi = malloc(sizeof(int) * size - 1);

	if (cpi == NULL)
		return;

	ft_copy_array(array, cpi, size);

	ft_mergeSort(cpi, 0, size, array);
	free(cpi);
}