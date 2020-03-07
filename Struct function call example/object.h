/*
 * object.h
 *
 *  Created on: Feb 23, 2020
 *      Author: jan
 */

#ifndef OBJECT_H_
#define OBJECT_H_

// Definition
// typedef function
// a function that requires two ints and returns an int result
typedef int (*Operation)(int a, int b);
// typedef of the object
typedef struct {
	int result1, result2;
	Operation g, h;
} object;
// constructor
object object_init(int a, int b);

#endif /* OBJECT_H_ */
