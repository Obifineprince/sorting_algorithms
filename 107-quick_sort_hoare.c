#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 * Return: void
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Partitions the array using Hoare's partition scheme.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 * Return: Index of the pivot element.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * quicksort_hoare - Recursive function to sort an array using quicksort
 *                   with Hoare's partition scheme.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 * Return: void
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = hoare_partition(array, low, high, size);
        quicksort_hoare(array, low, pivot, size);
        quicksort_hoare(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                    the Quick sort algorithm with Hoare's partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_hoare(array, 0, size - 1, size);
}
