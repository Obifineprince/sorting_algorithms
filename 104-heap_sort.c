#include "sort.h"
#include <stdio.h>

/**
 * sift_down - Perform sift-down operation on the heap.
 *
 * @array: The array representing the heap.
 * @start: The root index of the subtree to sift down.
 * @end: The end index of the heap (exclusive).
 * @size: The size of the array.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;
    int temp; 

    while (2 * root + 1 < end)
    {
        size_t child = 2 * root + 1;
        size_t swap = root;

        if (child + 1 < end && array[child] < array[child + 1])
            child++;

        if (array[root] < array[child])
            swap = child;

        if (swap == root)
            return;

        temp = array[root]; 
        array[root] = array[swap];
        array[swap] = temp;

        print_array(array, size);

        root = swap;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
    size_t i;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2; i > 0; i--)
        sift_down(array, i - 1, size, size);

    for (i = size - 1; i > 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        print_array(array, size);

        sift_down(array, 0, i, size);
    }
}
