/*
 * main.c
 *
 *  Created on: Dec 31, 2018
 *      Author: jan
 *
 *  knock knock server demonstrates read and write to client
 *
 */
//include files
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#include "helper.h"

//globals
int listener_d;
char buf[80];

//prototypes
void handle_shutdown(int sig);
int catch_signal(int sig, void (*handler)(int));

int main(){
	// register the CTRL-C handler with OS
	if (catch_signal(SIGINT, handle_shutdown) == -1) {
		fprintf(stderr, "Can't map the handler");
		exit(2);
	}
	/*
	 * After the server receives CTRL-C all child instances are closed
	 */
	// open socket
	listener_d = open_listener_socket();
	// BIND
	bind_to_port(listener_d, 30000);
	// LISTEN
	if (listen(listener_d, 10) == -1)
		error("Can't listen");
	while(1){
		// ACCEPT
		struct sockaddr_storage client_addr;
		// client_addr will store details about the client who’s just connected.
		unsigned int address_size = sizeof(client_addr);
		fprintf(stderr, "Waiting for connection..\n");
		// get connection from client
		int connect_d = accept(listener_d, (struct sockaddr *) &client_addr,
						&address_size);
		if (connect_d == -1)
			error("Can't open secondary socket");

		// Fork the code and spin off a new child to handle this request
		pid_t pid;

		pid = fork();
		/* fork()
		 * function returns 0 to the child process, and it will return a
		 * nonzero value to the parent process
		 */
		if (pid == -1) { // there is an issue with the forking
			error("Can't fork the process %s\n");
		}
		if (pid) // this is executed by the parent process only
			close(connect_d); // the parent doesn't need the connect_d process
		if (!pid) { // this is executed by the child process only

			// the child doesn't use the listener socket!
			close(listener_d);
			// BEGIN to talk
			say(connect_d, "Knock! knock!\n");

			if (!read_in(connect_d, buf, 80))
				puts(buf);

			if (!strncasecmp(buf, "Who's there?", 12)) {
				puts(buf);
				say(connect_d, "Oscar\n");

				if (!read_in(connect_d, buf, 80))
					puts(buf);

				if (!strncasecmp(buf, "Oscar who?\n", 10)) {
					puts(buf);
					say(connect_d,
							"Oscar silly question, you get a silly answer\n");
				}
			}

			say(connect_d, "Bye bye!\r\n");
			// close the connection
			close(connect_d);
			// close the process
			exit(0);
			// end of child code
		}
	}
	return 0;
}

/*
 * handle_shutdown closes the program when CTRL-C is received
 * by the OS
 *
 */
void handle_shutdown(int sig) {
	if (listener_d) // check for any open connections
		close(listener_d); // and close these
	fprintf(stderr, "Bye!\n");
	exit(0);
}

/*
 * catch_signal registers the handler
 *
 */
int catch_signal(int sig, void (*handler)(int)) {
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig, &action, NULL);
}
