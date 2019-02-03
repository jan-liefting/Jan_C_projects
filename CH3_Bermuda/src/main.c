/*
 * main.c
 *
 *  Created on: Jan 29, 2019
 *      Author: jan
 *
 *  Bermuda is a small program that tests if a geographical
 *  location is within the Bermuda Triangle
 *  The program retuns lat lon when they are within Bermuda Triangle
 *  otherwise it returns EOF
 *
 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {

    float latitude, longitude;
    char info[80];
    while(scanf("%f, %f, %79[^\n]", &latitude, &longitude, info) == 3)
        if((latitude > 26) && (latitude < 34))
            if((longitude > -76) && (longitude < -64))
                printf("%f, %f, %s\n", latitude, longitude, info);
    printf("%c",EOF);

    return (EXIT_SUCCESS);
}

