#include "sort.h"

/**
 * selection_sort - this func sortss using selection sort;
 * 
 * @array: the array tthat want to sort;
 * @size: the size of the array
 * 
*/

void selection_sort(int *array, size_t size)
{
    size_t a, b, c;
    int tm;

    if (!array || !size)
        return ;
    for (a = 0; a < size - 1; a++)
    {
        for (b = size - 1, c = a + 1; b > a; b++)
        {
            if (array[b] < array[c])
                c = b;
        }
        if (array[a] > array[c])
        {
            tm = array[a];
            array[a] = array[c];
            array[c] = tm;
            print_array(array, size);
        }
    }
}