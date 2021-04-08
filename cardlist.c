#include <stdlib.h>
#include <stdio.h>

#include "card.h"
#include "cardlist.h"
#include "memwatch.h"

/*
* purpose : create a new circularly linked list
* input   : None
* returns : An intitalized circularly linked list
*/  
List list_create(){

  return NULL;
}

/* 
* purpose : create a new node with a link, a private function
* input   : new_card - the card to insert into the node
*           next     - the node to link this one to. Links to itself if NULL
* return  : a new node for the list
*/
static Node* create_node(Card new_card, Node *next){
  Node *new_node = (Node *) malloc(sizeof(Node));
  if (new_node == NULL){
    perror("malloc");
    return NULL;
  }

  new_node->data=new_card;

  //make this node circular instead of defaulting to NULL
  if (next != NULL){
    new_node->next=next;
  } else {
    new_node->next=new_node;
  }

  return new_node;
}

/*
* purpose : add a card to the start of the list
* input   : list - a pointer to the list to add to
*           new_card - the card to add to the list
* return  : 1 if successful
*/
int list_add_start(List *list, Card new_card){

  if (*list == NULL){

    //The list is empty, so the node we create is the whole thing
    *list = create_node(new_card,*list);
    
    if (*list == NULL){
      return 0;
    }

  } else {

    //The list has an element, so go to the begining and add it there
    (*list)->next = create_node(new_card, (*list)->next);
    
    if ((*list)->next == NULL){
      return 0;
    }
  }

  return 1;
}

/*
* purpose : Add a node to the end of the list
* input   : list - a pointer to the list to add to
*           new_card - the card to add
* return  : 1 if successful.
*/
int list_add_end(List *list, Card new_card){

  // in a circularly linked list, adding to the end is the same as
  // adding to the begining, but you shift where you point
  if (list_add_start(list, new_card) == 1){
    *list=(*list)->next;  
    return 1;
  } else {
    return 0;
  }
}

/*
* purpose : Find a card in the list
* input   : list - the list to search
*           needle - the card to find
*           comparitor - function to be used to compare two cards. Return 0 on match.
* return  : the card found or INVALID_CARD
*/
Card list_find(List list, Card needle, int (*comparitor)(Card,Card)){

  Node *curr;
  
  // start at the begining and go till yo uget back to the end
  for( curr=list->next; curr != list; curr = curr->next){
    if(comparitor(curr->data,needle)==0){
      return curr->data;
    }
  }

  //if you get to the end, check if it's the one
  if(comparitor(curr->data,needle)==0){
      return curr->data;
  }
  
  return INVALID_CARD;
}

/*
* purpose : delete the searched or card
* input   : list   - a pointer to the list to delete from
*           needle - the card to delete
* return  : none
*/
void list_delete(List *list, Card needle){

  Node *prev=*list;
  Node *curr;

  if (*list == NULL){
    return;
  }

  //in a circularly link list, start at the start and go till the end
  for( curr=(*list)->next; curr != *list; curr = curr->next){
    
    if(card_compare(curr->data,needle)==0){
      break;
    }
    prev = curr;
  }

  //once you have wrapped around, check if the end is the one
  if (curr == *list && card_compare(curr->data,needle)!=0){
    return;
  }

  
  if (prev == curr){
    //this was the last item in the list
    *list=NULL;
  } else {
    //remove the one we found 
    prev->next=curr->next;
  }

  if (curr == *list){
    //if we removed the last item in the list, shuft the tail pointer back
    *list=prev;
  }

  free(curr);
  
}

/*
* purpose : free the list
* input   : list - a pointer to the list to free
* return  : none
*/
void list_free(List *list){
  Node *prev=*list;
  Node *curr;  

  if (*list == NULL){
    return;
  }

  //start at the start and go to the end in a circular list
  for( curr=(*list)->next; curr != *list; curr = curr->next){
    free(prev);
    prev = curr;
  }

  free(prev);

}

/*
* purpose : print out all the cards in the list
* input   : list - the list to print
* return  : nothing (printing to the screen is a side effect)
*/
void list_print(List list){
  Node *curr;  

  if (list == NULL){
    return;
  }

  //start at the start and go to the end in a circular list
  for( curr=list->next; curr != list; curr = curr->next){
    card_print(curr->data);
    printf(",");
  }

  card_print(curr->data);
}
