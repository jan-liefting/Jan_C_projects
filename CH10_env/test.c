/*
 * test.c
 *
 *  Created on: Aug 17, 2018
 *      Author: jan
 */

//include files
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	printf("Program: %s\n", argv[0]);
	printf("Diners: %s\n", argv[1]);
	printf("Drinks: %s\n", getenv("DRINKS"));
	printf("Juice: %s\n", getenv("JUICE"));

	return 0;
}

/*
 * Note: the arguments and the name=value pairs for this
 * program are set in Run/Debug settings
 */
