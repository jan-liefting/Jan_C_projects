/*
 * main.c
 *
 *  Created on: Aug 11, 2019
 *      Author: jan
 */

// includes
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>

// globals
int beers = 2000000;

// MUTEX
pthread_mutex_t a_lock = PTHREAD_MUTEX_INITIALIZER;

/*
 * drink_lots lowers the global variable beers by 100.000
 */
void *drink_lots(void *a)
{
	int i;
	pthread_mutex_lock(&a_lock);
	for(i = 0; i < 100000; i++)
	{
		// start of atomic function
		//pthread_mutex_lock(&a_lock);
		beers -= 1;
		//pthread_mutex_unlock(&a_lock);
	}
	pthread_mutex_unlock(&a_lock);

	printf("beers = %i\n", beers);
	return NULL;
}

int main(int argc, char **argv)
{

	// setup and start the threads
	pthread_t threads[20];
	int t;
	for(t = 0; t < 20; t++)
		if(pthread_create(threads + t, NULL, drink_lots, NULL) == -1)
			perror("Can't create thread t0");

	// store the result of the threads
	void *result;
	for(t = 0; t < 20; t++)
		if(pthread_join(threads[t], &result) == -1)
			perror("Can't join thread t0");

	printf("There are now %i bottles of beer on the wall\n", beers);

	return (0);
}
