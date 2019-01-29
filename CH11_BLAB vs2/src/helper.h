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

/*
 * error prints an error message to the stderr
 */
void error(char* message);

/*
 * open_listener creates a socket
 */
int open_listener_socket();

/*
 * bind_to_port binds to port 30000
 */
void bind_to_port(int socket, int port);

/*
 * say sends a string to socket
 */
int say(int socket, char *s);

#endif /* SRC_HELPER_H_ */
