/*
 * main.c
 *
 *  Created on: May 15, 2019
 *      Author: jan
 */
/*** includes ***/
#include <stdio.h>
#include <stdlib.h>

#include "Snappy.h"

/*** globals ***/
/*** prototypes ***/
/*** see Snappy.h file ***/
/*
 *
 */
int main(int argc, char** argv) {
    struct fish snappy = {"Snappy", "Piranha", 69,4,{{"meat", 0.2}, {"Swim in the jacuzzi", 7.5}}};

    label(snappy);


    return (EXIT_SUCCESS);
}

void label(struct fish a) {
    printf("Name:%s\nSpecies:%s\n%i years old, %i teeth\n", a.name, a.species, a.teeth, a.age);
    printf("Feed with %2.2f lbs of %s and allow to %s for %2.2f hours\n", a.care.food.weight, a.care.food.ingredients,
    a.care.excercise.description, a.care.excercise.duration);
}

