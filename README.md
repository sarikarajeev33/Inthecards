# It's in the Cards
The goal of this assignment is to add functionality to your card list. 
You want to be able to find cards in the old way, but also by suit or rank.

(Note: You have been provided a circularly linked list implementation of Assignment 3 to work with).

# Details
1. Update cardlist.c/h and card.c/h to provide functionality to search for the first matching card by suit or rank.  
    * Remember that card.c/h contains card behavior and knows nothing of the list while cardlist.c/h contains list behavior and knows nothing of how cards behave. For example, the function to find cards by suit should look like ```Card list_suit_find(List list, Card card_suit)``` so as to not assume how suits are stored. This means you will need new functiosn in card.c/h like ```int card_suit_compare(Card card_a, Card card_b)```.
2. Edit cardmain.c to call your new functions. Demonstrate to your instructor that they work.
3. Examine your functions in cardlist.c and notice the similarities in ```list_find```, ```list_rank_find```, and ```list_suit find```.
4. Use these similarities to write ```list_fp_find``` which uses function pointers to decide what to find.
5. Update cardmain to use your new function pointer function!
