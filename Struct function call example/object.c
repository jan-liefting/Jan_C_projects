/*
 * object.c
 *
 *  Created on: Feb 23, 2020
 *      Author: jan
 */

#include "object.h"

// Definitions

// Declarations
// static variables only visible in this source file
static int i = 0;
static object z;

static int sum(int a, int b){
	return a + b;
}

static int multiply(int a, int b){
	return a * b;
}

//create object
object object_init(int a, int b){
	z.g = sum;
	z.h = multiply;
	z.result1 = z.g(a, b);
	z.result2 = z.h(a, b);
	// return object to caller
	return z;
}
