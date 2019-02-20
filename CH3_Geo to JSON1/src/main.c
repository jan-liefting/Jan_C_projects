/*
 * main.c
 *
 *  Created on: Feb 20, 2019
 *      Author: jan
 */

// include files
#include <stdio.h>
#include <stdlib.h>

// globals

/*
 *
 */
int main(int argc, char** argv) {

    float latitude;
    float longitude;
    char info[80];
    int started = 0;
    puts("data=[");
    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info)) {
        //check for valid latitude and longitude
        if(latitude<-90 || latitude>90){
            fprintf(stderr, "Latitude outside of range\n");
            return(2);
        }
        if(longitude<-180 || longitude>180){
            fprintf(stderr, "Longitude outside of range\n");
            return(2);
        }

        if (started)
            printf(",\n");
        else
            started = 1;
        printf("{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
    }
    puts("\n]");

    return (EXIT_SUCCESS);
}
