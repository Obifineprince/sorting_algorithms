#include "sort.h"
#include <stdio.h>

void bit_sort(char up, int *array, size_t size, size_t t); 

/**
 * bitonic_compare - Compares and sorts the values in a sub-array using
 *                   the Bitonic sort algorithm.
 * @up: The direction of sorting (1 for ascending, 0 for descending).
 * @array: The sub-array to sort.
 * @size: The size of the sub-array.
 * Return: void
 */
void bitonic_compare(char up, int *array, size_t size)
{
    size_t i, dist;
    int swap;

    dist = size / 2;
    for (i = 0; i < dist; i++)
    {
        if ((array[i] > array[i + dist]) == up)
        {
            swap = array[i];
            array[i] = array[i + dist];
            array[i + dist] = swap;
        }
    }
}

/**
 * bitonic_merge - Recursive function that merges two sub-arrays
 *                 using the Bitonic sort algorithm.
 * @up: The direction of sorting (1 for ascending, 0 for descending).
 * @array: The sub-array to sort.
 * @size: The size of the sub-array.
 * Return: void
 */
void bitonic_merge(char up, int *array, size_t size)
{
    if (size < 2)
        return;
    bitonic_compare(up, array, size);
    bitonic_merge(up, array, size / 2);
    bitonic_merge(up, array + (size / 2), size / 2);
}

/**
 * bit_sort - Recursive function using the Bitonic sort algorithm.
 * @up: The direction of sorting (1 for ascending, 0 for descending).
 * @array: The sub-array to sort.
 * @size: The size of the sub-array.
 * @t: The total size of the original array.
 * Return: void
 */
void bit_sort(char up, int *array, size_t size, size_t t)
{
    if (size < 2)
        return;
    printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
    print_array(array, size);
    bit_sort(1, array, size / 2, t);
    bit_sort(0, array + (size / 2), size / 2, t);
    bitonic_merge(up, array, size);
    printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
    print_array(array, size);
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    bit_sort(1, array, size, size);
}
