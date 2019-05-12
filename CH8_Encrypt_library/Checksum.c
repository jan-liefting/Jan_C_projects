/*
 * Checksum.c
 *
 *  Created on: Aug 13, 2018
 *      Author: jan
 */

//includes
#include "Checksum.h"

//globals

//functions
int checksum(char *message) {
	int c = 0;
	int checksum(char *message);
	while (*message) {
		c += c ^ (int) (*message);
		message++;
	}
	return c;
}
