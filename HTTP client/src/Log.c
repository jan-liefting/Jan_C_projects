/*
 * Log.c
 *
 * generic functions to create a log file with messages and
 * timestamps
 *
 *  Created on: Aug 14, 2019
 *      Author: jan
 */

// includes
#include "Log.h"

/*
 * when called it returns a statically allocated string which
 * holds the system time stamp
 * format: "Tue May 21 13:46:22 1991\n"
 *
 */
char *now()
{
	time_t t;

	if(time(&t) == -1)
		perror("Unable to create a time structure for logging");

	return asctime(localtime(&t));
}

void init_logfile(void)
{
	logfile = 1;
	return;
}
