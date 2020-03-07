/*
 * object.h
 *
 *  Created on: Feb 23, 2020
 *      Author: jan
 */

#ifndef OBJECT_H_
#define OBJECT_H_

//#define NUM_OBJECTS 10
// Definition
// typedef function
typedef int (*Operation)(int a, int b);
// typedef of the object
typedef struct {
	int result1, result2;
	Operation g, h;
} object;
// constructor
object object_init(int a, int b);

#endif /* OBJECT_H_ */
