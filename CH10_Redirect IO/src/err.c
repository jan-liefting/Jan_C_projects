/*
 * err.c
 *
 *  Created on: Jul 28, 2019
 *      Author: jan
 */

#include "err.h"

void error(char* msg){
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

