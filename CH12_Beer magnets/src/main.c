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

/*
 * drink_lots lowers the global variable beers by 100.000
 */
void *drink_lots(void *a)
{
	int i;
	for(i = 0; i < 100000; i++)
		beers -= 1;
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

	return (0);
}
