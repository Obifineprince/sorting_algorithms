#include "sort.h"
#include <stdlib.h>

/**
 * count_array - Creates the count array.
 * @array: Array of integers.
 * @size: Size of the array.
 * @k: Largest number in the unsorted array.
 * Return: The count array.
 */
int *count_array(int *array, size_t size, int k)
{
    int *count_array;
    size_t i, j;

    count_array = malloc((k + 1) * sizeof(int));
    if (count_array == NULL)
        return (NULL);

    for (i = 0; i < (k + 1); i++)
        count_array[i] = 0;

    for (j = 0; j < size; j++)
        count_array[array[j]]++;

    for (i = 1; i <= k; i++)
        count_array[i] = count_array[i] + count_array[i - 1];

    print_array(count_array, k + 1);

    return (count_array);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
    int *temp_array, max_num, *count_array;
    size_t i, j;

    if (array == NULL || size < 2)
        return;

    max_num = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] > max_num)
            max_num = array[i];
    }

    count_array = count_array(array, size, max_num);
    if (count_array == NULL)
        return;

    temp_array = malloc(size * sizeof(int));
    if (temp_array == NULL) {
        free(count_array);
        return;
    }

    for (j = size - 1; j >= 0; j--)
        temp_array[--count_array[array[j]]] = array[j];

    for (i = 0; i < size; i++)
        array[i] = temp_array[i];

    free(temp_array);
    free(count_array);
}
