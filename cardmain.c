#include <stdio.h>
#include <stdlib.h>

#include "cardlist.h"
#include "card.h"

#define INSERT_BEGINNING 'b'
#define INSERT_END       'e'
#define DELETE           'd'
#define FIND             'f'
#define PRINT            'p'
#define QUIT             'q'
#define HELP             '?'
#define RANK             'r'
#define SUIT             's'

static const int BUFFER_LENGTH=1024;


/* purpose: print a message and terminate the program
 * input:   the message
 * returns: never!! terminates progam
 */
static void die(char *msg)
{
  perror(msg);
  exit(-1);
}

static void menu(){
  printf("\t%c - Insert at the beginning\n",INSERT_BEGINNING);
  printf("\t%c - Insert at the end\n",INSERT_END);
  printf("\t%c - Delete an item\n",DELETE);
  printf("\t%c - Find a card\n",FIND);
  printf("\t%c - Print the list\n",PRINT);
  printf("\t%c - Quit\n",QUIT);
  printf("\t%c - Find a card by Suit\n",SUIT);
  printf("\t%c - Find a card by Rank\n",RANK); 
  printf("\t%c - Print this menu\n",HELP);

}

/*purpose: read and process card list commands
 * input:   nothing
 * returns: 0 (it always works ;) )
 */
int main(int argc, char *argv[])
{
  char command[BUFFER_LENGTH];
  List list = list_create();
  Card card;
  Card found_card;

  printf("Welcome to the card list maker. Options are:\n");
  menu();

  while (1)
  {
    printf("Command: ");
    fflush(stdin);
    if (fgets(command, BUFFER_LENGTH,stdin) ==NULL)
      die("fgets");

    if (*command == INSERT_BEGINNING  || *command == INSERT_END ||
        *command == DELETE            || *command == FIND       ||
        *command == SUIT              || *command == RANK)
    {
      printf("Enter a card as 1 character rank (2-9,T,J,Q,K,A)");
      printf(" and suit (H,C,S,D)\n");
      card = card_read();
      if (card_compare(card,INVALID_CARD)==0){
        printf("Not a valid card\n");
        continue;
      }
    }

    switch (*command)
    {
      case DELETE: list_delete(&list, card); break;
      case FIND:
            found_card = list_find(list, card, card_compare);
            break;
      case RANK:
            found_card = list_find(list, card, card_rank_compare);
            break;
      case SUIT:
            found_card = list_find(list, card, card_suit_compare);
            break;
      case INSERT_BEGINNING: list_add_start(&list, card); break;
      case INSERT_END: list_add_end(&list, card); break;
      case PRINT: list_print(list); printf("\n"); break;
      case QUIT: list_free(&list); return 0;
      case HELP: menu(); break;
      default: printf("Invalid command! Options:\n"); menu(); break;
    }
    if (*command == FIND || *command == RANK || *command == SUIT){
      if (card_compare(found_card, INVALID_CARD) == 0){
        printf("Card not found\n");
      } else {
        printf("Found: ");
        card_print(found_card);
        printf("\n");
      }
    }
  }

  return 0;
}

