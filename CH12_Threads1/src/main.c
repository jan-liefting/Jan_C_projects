/*
 * main.c
 *
 *  Created on: Aug 5, 2019
 *      Author: jan
 */

// includes
#include <pthread.h>
#include "helper.h"

// prototypes
void *does_not(void *a);
void *does_too(void *a);



int main(int argc, char **argv){

	// setup and start the two threads
	pthread_t t0;
	pthread_t t1;
	if(pthread_create(&t0, NULL, does_not, NULL) == -1)
		error("Can't create thread t0");
	if(pthread_create(&t1, NULL, does_too, NULL) == -1)
		error("Can't create thread t1");

	// store the result of the threads
	void *result;
	if(pthread_join(t0, &result)  == -1)
		error("Can't join thread t0");
	if(pthread_join(t1, &result)  == -1)
			error("Can't join thread t1");

	return(0);
}

void *does_not(void *a) {
	int i = 0;
	for (i = 0; i < 5; i++) {
		for (i = 0; i < 5; i++) {
			sleep(1);
			puts("Does not!");
		}
	}
	return NULL;
}

void *does_too(void *a){
	int i = 0;
	for (i = 0; i < 5; i++) {
		for (i = 0; i < 5; i++) {
			sleep(1);
			puts("Does too!");
		}
	}
	return NULL;
}
