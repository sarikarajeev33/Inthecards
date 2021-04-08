#ifndef CARDLIST_H
#define CARDLIST_H

#include "card.h"

typedef struct node_s{
  Card data;
  struct node_s* next;
} Node;

typedef  Node* List;

List list_create();
int list_add_start(List *list, Card new_card);
int list_add_end(List *list, Card new_card);
Card list_find(List list, Card needle, int (*comparitor)(Card,Card));
void list_delete(List *list, Card to_delete);
void list_free(List *list);
void list_print(List list);

#endif
