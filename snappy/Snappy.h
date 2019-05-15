/*
 * Snappy.h
 *
 *  Created on: May 15, 2019
 *      Author: jan
 */

#ifndef SNAPPY_H_
#define SNAPPY_H_

/*** global definitions ***/
struct exercise{
    const char *description;
    float duration;
};
struct meal{
    const char *ingredients;
    float weight;
};
struct preferences{
    struct meal food;
    struct exercise excercise;
};
struct fish{
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences care;
};

/*** prototypes ***/
void label(struct fish);

#endif /* SNAPPY_H_ */
