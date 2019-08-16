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

//globals
static int logfile = 0;
static int initialized = 0;

/*
 * when called it returns a statically allocated string which
 * holds the system time stamp
 * format: "Tue May 21 13:46:22 1991\n"
 *
 */
static char *now()
{
	time_t t;

	if(time(&t) == -1)
		perror("Unable to create a time structure for logging");

	return asctime(localtime(&t));
}

/*
 * initialize log file to signal that we need to keep track of
 * the logs
 */
void init_logfile(void)
{
	logfile = initialized = 1;

	// initialize the log file

	return;
}

void pause_logfile(void)
{
	if(initialized)
		logfile = 0;
	else
		perror("Can't pauze the log; it's not initialized");

	return;
}

void resume_logfile(void)
{
	if(initialized)
		logfile = 1;
	else
		perror("Can't resume the log; it's not initialized");
	logfile = 1;

	return;
}

void close_logfile(void)
{
	logfile = initialized = 0;

	// close the log file

	return;
}

/*
 * places the message on the log, adding a timestamp
 * if the logfile is disabled it returns -1
 * if the logfile is not initialized, the routine exits through perror()
 */
int log_message(char *message)
{
	if(!initialized)
			perror("Can't process the message; log is not initialized");

	if(!logfile)
		return -1;

	printf("%s\t%s", now(), message);
	return 1;
}
