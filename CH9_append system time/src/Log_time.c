/*
 * Log_time.c
 *
 *  Created on: Jul 26, 2019
 *      Author: jan
 */

// includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* now(){
	time_t t;
	time(&t);
	return asctime(localtime(&t));
}

/* Master Control Progam Utility
 * Record guard patrol check-ins
 */

int main(){
	char comment[80];
	char cmd[120];

	// read comment from stdin
	fgets(comment, 80, stdin);
	sprintf(cmd, "echo '%s %s' >> reports.log", comment, now());

	// call system with command: cmd
	system(cmd);
	return 0;
}
