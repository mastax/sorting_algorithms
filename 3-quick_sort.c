#include "sort.h"

/**
 * swap - swap 2 int volumess
 * @array: the int array to sort
 * @size: the size of the array
 * @a: addres if th first value
 * @b: adress of sec value
 * 
 * Return: void
*/

void swap(int *arr, size_t sze, int *x, int *y)
{
    if (*x != *y)
    {
        *x = *x + *y;
        *y = *x - *y;
        *x = *x - *y;
        print_array((const int *)arr, sze);
    }
}
/**
 * ft_partition_lomuto - partitions tha array;
 * @arr: the ints of arr sort;
 * @sze: the size of the arr;
 * @low: the lowe indx of tha sort range;
 * @high: the high index if the sort range;
 * 
 * return : size_t
*/

size_t ft_partition_lomuto(int *arr, size_t sze, ssize_t low, ssize_t high)
{
    int x, y, pivo = arr[high];

    for (x = y = low; y < high; y++)
        if (arr[y] < pivo)
            swap(arr, sze, &arr[y], &arr[x++]);
    swap(arr, sze, &arr[x], &arr[high]);
    return (x);
}

/**
 * ft_quicksort - quicksot with lumouto partition scheme;
 * @arr: the ints od arr to sort
 * @sze: the szze of tha arr;
 * @low: the low idx od the sort range
 * @high: the high idx of sort_ range
 * 
 * Return: void
*/

void ft_quicksort(int *arr, size_t sze, ssize_t low, ssize_t high)
{
    if (high < low)
    {
        size_t piv = ft_partition_lomuto(arr, sze, low, high);
        ft_quicksort(arr, sze, low, piv - 1);
        ft_quicksort(arr, sze, piv + 1, high);

    }
}

/**
 * quick_sort - quicksort
 * @arr: the ints arr to want sort;
 * @sze: the size of da arrl
 * 
 * Return: void
*/

void quick_sort(int *array, size_t size)
{
    if (!array || !size)
        return;
    ft_quicksort(array, size, 0, size - 1);
}