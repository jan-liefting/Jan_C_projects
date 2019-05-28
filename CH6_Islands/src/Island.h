/*
 * Island.h
 *
 *  Created on: May 27, 2019
 *      Author: jan
 */

#ifndef ISLAND_H_
#define ISLAND_H_

//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//globals
typedef struct island{
	char *name;
	char *opens;
	char *closes;
	struct island *next;
} island;

//prototypes
void display(island*);
island* create(char*);


#endif /* ISLAND_H_ */
