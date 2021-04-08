#ifndef CARD_H
#define CARD_H

typedef struct card_s{
  int rank;
  int suit;
} Card;

static const Card INVALID_CARD= {0,0};

Card card_create(int suit, int rank);
void card_print(Card c);
int card_compare(Card c1, Card c2);
int card_rank_compare(Card c1, Card c2);
int card_suit_compare(Card c1, Card c2);
Card card_read();

#endif
