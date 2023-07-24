#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: First element
 * @b: Second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * partition - Partitions the array and returns the pivot index
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Pivot index
 */
int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, high + 1);
        }
    }
    swap(&array[i + 1], &array[high]);
    print_array(array, high + 1);

    return (i + 1);
}

/**
 * quicksort - Implements the quicksort algorithm
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void quicksort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(array, low, high);

        quicksort(array, low, pivot - 1);
        quicksort(array, pivot + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1);
}
