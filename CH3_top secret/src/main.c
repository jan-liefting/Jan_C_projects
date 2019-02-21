/*
 * main.c
 *
 *  Created on: Feb 21, 2019
 *      Author: jan
 */
#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main(int argc, char** argv) {

    char word[10];
    int i = 0;
    while(scanf("%9s", word) == 1){
        i += 1;
        if(i % 2)
            fprintf(stdout, "%s\n", word);
        else
            fprintf(stderr, "%s\n", word);

    }

    return (EXIT_SUCCESS);
}

