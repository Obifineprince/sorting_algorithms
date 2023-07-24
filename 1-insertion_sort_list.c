#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked
 * list of integers in ascending order
 * using Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *sorted, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    sorted = *list;
    current = sorted->next;

    while (current != NULL)
    {
        while (current->prev != NULL && current->n < current->prev->n)
        {
            temp = current->prev;
            temp->next = current->next;
            if (current->next != NULL)
                current->next->prev = temp;

            current->next = temp;
            current->prev = temp->prev;
            temp->prev = current;

            if (current->prev == NULL)
                *list = current;
            else
                current->prev->next = current;

            print_list(*list);
        }

        current = current->next;
    }
}
