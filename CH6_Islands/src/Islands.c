/*
 * Islands.c
 *
 *  Created on: May 27, 2019
 *      Author: jan
 */

// includes

#include "Island.h"

int main(){

	island *start = NULL;
	island *i = NULL;
	island *next = NULL;

	char name[80];
	for(;fgets(name, 80, stdin) != NULL; i = next){
		next = create(name);
		if(start == NULL) // sets the start of the linked list
			start = next;
		if(i != NULL)
			i->next = next;
	}
	display(start);

	release(start);

	return 1;
}

// helper functions
void display(island *start){
	island *i = start;
	for(;i != NULL; i = i->next){
		printf("Name: %s open: %s-%s", i->name, i->opens, i->closes);
	}
}

island *create(char *name){
	island *i = malloc(sizeof(island));
	i->name = strdup(name);
	i->opens = "09:00";
	i->closes = "17:00";
	i->next = NULL;

	return i;
}

void release(island* start){
	island *i = start;
	island *next = NULL;
	for(;i != NULL; i = next){
		next = i->next;
		free(i->name);
		free(i);
	}

}
