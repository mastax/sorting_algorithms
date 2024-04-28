#include "sort.h"

/**
 * shell_sort - tha Shell sort - Knuth Sequence
 * @array: array to sort::
 * @size: size of array::
 * 
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int gp = 1, x, y, temp;

	while (gp < ((int)(size)))
		gp = (3 * gp) + 1;
	for (gp = (gp - 1) / 3; gp > 0; gp = (gp - 1) / 3)
	{
		for (x = gp; x < (int)size; x += 1)
		{
			temp = array[x];

			for (y = x; y >= gp && array[y - gp] > temp; y -= gp)
				array[y] = array[y - gp];

			array[y] = temp;
		}
		print_array(array, size);
	}
}