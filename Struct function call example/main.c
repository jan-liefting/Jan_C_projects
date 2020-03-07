/*
 * main.c
 *
 *  Created on: Feb 3, 2020
 *      Author: jan
 *
 *  Example of a struct that contains a function
 */
// Include files standard libraries
#include <stdio.h>

// Include files other
#include "object.h"

// global definition
object a, b;


int main(){
	a = object_init(1, 2); // initialization of a; make a copy of the object and assign to a
	b = object_init(3, 4); // initialization of b; make a copy of the object and assign to b

	printf("1 + 2 = %d\n", a.result1);
	printf("3 x 4 = %d\n", b.result2);

	return 0;
}
