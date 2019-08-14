/*
 * HTTP_helper.h
 *
 *  Created on: Aug 14, 2019
 *      Author: jan
 */

#ifndef HTTP_HELPER_H_
#define HTTP_HELPER_H_



#endif /* HTTP_HELPER_H_ */

// includes
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>

#include "Log.h"

//defines
#define MAX_GET_COMMAND 255
#define BUFFER_SIZE 255

// prototypes

int parse_url(char *uri, char **host, char **path);
int http_get(int connection, const char *path, const char *host);
void display_result(int connection);

