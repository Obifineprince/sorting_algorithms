#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - enumeration of card kinds
 */
typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * struct card_s - structure representing a card
 * @value: string containing the value of the card ("Ace", "2", ..., "10",
 *         "Jack", "Queen", or "King")
 * @kind: kind of the card (SPADE, HEART, CLUB, or DIAMOND)
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * struct deck_node_s - structure representing a node in a deck of cards
 * @card: pointer to the card represented by the node
 * @prev: pointer to the previous node in the deck (or NULL if none)
 * @next: pointer to the next node in the deck (or NULL if none)
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
