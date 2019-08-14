/*
 * Log.h
 *
 *  Created on: Aug 14, 2019
 *      Author: jan
 */

#ifndef LOG_H_
#define LOG_H_



#endif /* LOG_H_ */

// includes
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <string.h>


// prototypes
void init_logfile(void);
void pause_logfile(void);
void resume_logfile(void);
void close_logfile(void);
int log_message(char *);
