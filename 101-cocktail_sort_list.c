#include "sort.h"

/**
 * swap - Swaps a node with its next node in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node: Node to be swapped
 */
void swap(listint_t **list, listint_t *node)
{
    node->next->prev = node->prev;
    if (node->prev)
        node->prev->next = node->next;
    else
        *list = node->next;

    node->prev = node->next;
    node->next = node->next->next;
    node->prev->next = node;

    if (node->next)
        node->next->prev = node;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *tmp;

    if (list == NULL || *list == NULL)
        return;

    tmp = *list;
    while (swapped)
    {
        swapped = 0;
        while (tmp->next)
        {
            if (tmp->next->n < tmp->n)
            {
                swap(list, tmp);
                swapped = 1;
                print_list(*list);
            }
            else
                tmp = tmp->next;
        }

        if (swapped == 0)
            break;

        swapped = 0;
        while (tmp->prev)
        {
            if (tmp->prev->n > tmp->n)
            {
                swap(list, tmp->prev);
                swapped = 1;
                print_list(*list);
            }
            else
                tmp = tmp->prev;
        }
    }
}
