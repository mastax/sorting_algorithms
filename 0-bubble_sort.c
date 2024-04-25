#include "sort.h"
/**
 * bubble_sort - Function that sorts an array of ints
 * using Bubble sort algo
 * 
 * @array: array of integers,
 * @size: size of the array that we want sort,
*/
void bubble_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size)
{
    int temp;
    size_t idx, kdx;

    if (!array || !size)
        return ;
    
    idx = 0;
    while (idx < size)
    {
        for(kdx= 0; kdx < size - 1; kdx++)
        {
            if (array[kdx] > array[kdx + 1])
            {
                temp = array[kdx];
                array[kdx] = array[kdx + 1];
                array[kdx + 1] = temp;
                print_array(array, size);        
            }
        }
        idx++;
    }
}
