/*
 * Islands.c
 *
 *  Created on: May 27, 2019
 *      Author: jan
 */

// includes

#include "Island.h"

int main(){

	char name[80];
	fgets(name, 80, stdin);
	island *p_island0 = create(name);
	fgets(name, 80, stdin);
	island *p_island1 = create(name);

	island amity = {"Amity", "09:00", "17:00", NULL};
	island craggy = {"Craggy", "09:00", "17:00", NULL};
	island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
	island shutter = {"Shutter", "09:00", "17:00", NULL};

	display(p_island0);
	display(p_island1);
	return 1;
}

// helper functions
void display(island *start){
	island *i = start;
	for(;i != NULL; i = i->next){
		printf("Name: %s open: %s-%s", i->name, i->opens, i->closes);
	}
}

island* create(char *name){
	island *i = malloc(sizeof(island));
	i->name = strdup(name);
	i->opens = "09:00";
	i->closes = "17:00";
	i->next = NULL;

	return i;
}
