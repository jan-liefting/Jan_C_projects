/*
 * helper.h
 *
 *  Created on: Dec 31, 2018
 *      Author: jan
 *
 *	helper.h consists of helper functions for Internet applications
 */

#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_


// includes
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/*
 * error prints an error message to the stderr
 */
void error(char* message);

/*
 * open_listener creates a socket
 */
int open_listener_socket();

/*
 * open_socket opens a socket based on a host url
 */
int open_socket(char *host, char *port);

/*
 * bind_to_port binds to port 30000
 */
void bind_to_port(int socket, int port);

/*
 * say sends a string to socket
 */
int say(int socket, char *s);

/*
 * read_in reads characters from the socket until we encounter /n
 */
int read_in(int socket, char *buf, int len);


#endif /* SRC_HELPER_H_ */
