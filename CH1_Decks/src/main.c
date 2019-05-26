/*
 * main.c
 *
 *  Created on: Feb 1, 2019
 *      Author: jan
 *
 *  Program to calculate the number of cards in the shoe.
 */
//includes
#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main() {
    int decks;
    puts("Enter a number of decks");
    scanf("%i", &decks);
    if (decks < 1) {
        puts("That is not a valid number of decks");
        return 1;
    }
    printf("There are %i cards\n", (decks * 52));
    return EXIT_SUCCESS;
//test
}

