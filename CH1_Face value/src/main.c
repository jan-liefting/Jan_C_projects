/*
 * main.c
 *
 *  Created on: Feb 6, 2019
 *      Author: jan
 *
 *  Waits for input and returns the face value of a card
 *  input {'J', 'Q', 'K', 'A', 0-9}
 *  output is the face value of the card
 */
//includes
#include <stdio.h>
#include <stdlib.h>Q

int main() {
    char card_name[3];
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
    int val = 0;
    if (card_name[0] == 'K') {
        val = 10;
    } else if (card_name[0] == 'Q') {
        val = 10;
    } else if (card_name[0] == 'J') {
        val = 10;
    } else if (card_name[0] == 'A') {
        val = 11;
    } else {
        val = atoi(card_name);
    }

    printf("The card value is: %i\n", val);
    return 0;
}

