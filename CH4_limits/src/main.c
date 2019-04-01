/*
 * main.c
 *
 *  Created on: Apr 1, 2019
 *      Author: jan
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>


int main(int argc, char** argv) {
    printf("The value of CHAR_MAX is %i\n", CHAR_MAX);
    printf("The value of CHAR_MIN is %i\n", CHAR_MIN);
    printf("An char takes %lu bytes\n\n", sizeof(char));

    printf("The value of INT_MAX is %i\n", INT_MAX);
    printf("The value of INT_MIN is %i\n", INT_MIN);
    printf("An int takes %lu bytes\n\n", sizeof(int));

    printf("The value of SHORT_MAX is %i\n", SHRT_MAX);
    printf("The value of SHORT_MIN is %i\n", SHRT_MIN);
    printf("An short takes %lu bytes\n\n", sizeof(short));

    printf("The value of LONG_MAX is %li\n", LONG_MAX);
    printf("The value of LONG_MIN is %li\n", LONG_MIN);
    printf("An long takes %lu bytes\n\n", sizeof(long));

    printf("The value of FLT_MAX is %f\n", FLT_MAX);
    printf("The value of FLT_MIN is %.50f\n", FLT_MIN);
    printf("A float takes %lu bytes\n\n", sizeof(float));

    printf("The value of DBL_MAX is %e\n", DBL_MAX);
    printf("The value of DBL_MIN is %e\n", DBL_MIN);
    printf("A double takes %lu bytes\n\n", sizeof(double));

    return (EXIT_SUCCESS);
}
