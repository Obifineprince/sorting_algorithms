#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * compare_cards - compares two cards
 * @card1: pointer to first card
 * @card2: pointer to second card
 *
 * Return: negative value if card1 is less than card2,
 *         positive value if card1 is greater than card2,
 *         zero if card1 is equal to card2.
 */
int compare_cards(const void *card1, const void *card2)
{
    const card_t *c1 = (*(deck_node_t **)card1)->card;
    const card_t *c2 = (*(deck_node_t **)card2)->card;
    int value_cmp = strcmp(c1->value, c2->value);
    if (value_cmp != 0)
        return value_cmp;
    return c1->kind - c2->kind;
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: pointer to pointer to head node of deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t i, len = 0;
    deck_node_t *node = *deck;
    deck_node_t **cards;

    while (node != NULL)
    {
        len++;
        node = node->next;
    }

    cards = malloc(len * sizeof(*cards));
    if (cards == NULL)
        return;

    node = *deck;
    for (i = 0; i < len; i++)
    {
        cards[i] = node;
        node = node->next;
    }

    qsort(cards, len, sizeof(*cards), compare_cards);

    for (i = 0; i < len; i++)
    {
        cards[i]->prev = i == 0 ? NULL : cards[i-1];
        cards[i]->next = i == len-1 ? NULL : cards[i+1];
    }

    *deck = cards[0];
    free(cards);
}
