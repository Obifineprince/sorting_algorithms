#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two sorted subarrays from the source array into the destination array.
 *
 * @start: Starting index (inclusive) for the left subarray.
 * @middle: End index (exclusive) for the left subarray and starting index (inclusive) for the right subarray.
 * @end: End index (exclusive) for the right subarray.
 * @dest: Destination for merged data.
 * @source: Source array to merge from.
 *
 * This function takes two adjacent sorted subarrays from the source array and merges them into
 * the destination array in ascending order. The left subarray is from 'start' to 'middle-1',
 * and the right subarray is from 'middle' to 'end-1'.
 */
void merge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
    size_t i = start, j = middle, k;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(source + start, middle - start);
    printf("[right]: ");
    print_array(source + middle, end - middle);

    for (k = start; k < end; k++)
    {
        if (i < middle && (j >= end || source[i] <= source[j]))
        {
            dest[k] = source[i];
            i++;
        }
        else
        {
            dest[k] = source[j];
            j++;
        }
    }

    printf("[Done]: ");
    print_array(dest + start, end - start);
}

/**
 * split_merge - Recursively splits the array and merges the sorted subarrays.
 *
 * @start: Starting index (inclusive) of the current subarray.
 * @end: End index (exclusive) of the current subarray.
 * @array: The array to sort.
 * @copy: A duplicate of the array for merging purposes.
 *
 * This function recursively divides the
   array into smaller subarrays until they are of size 1 or 0.
 * Then, it merges the sorted subarrays back
   into the original array in ascending order.
 */
void split_merge(size_t start, size_t end, int *array, int *copy)
{
    size_t middle;

    if (end - start < 2)
        return;

    middle = (start + end) / 2;

    split_merge(start, middle, copy, array);

    split_merge(middle, end, copy, array);

    merge(start, middle, end, array, copy);

    for (middle = start; middle < end; middle++)
        copy[middle] = array[middle];
}

/**
 * merge_sort - Sorts an array of integers
   in ascending order using the Merge sort algorithm.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * This function implements the Merge sort algorithm,
   which sorts the given array in ascending order.
 * It creates a duplicate of the array to assist in
   merging during the sorting process.
 * After sorting, the duplicate array is freed.
 */
void merge_sort(int *array, size_t size)
{
    size_t i;
    int *copy;

    if (array == NULL || size < 2)
        return;

    copy = malloc(sizeof(int) * size);
    if (copy == NULL)
        return;

    for (i = 0; i < size; i++)
        copy[i] = array[i];

    split_merge(0, size, array, copy);

    free(copy);
}
