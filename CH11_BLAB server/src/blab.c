/*
 * blab.c
 *
 *  Created on: Dec 29, 2018
 *      Author: jan
 *
 *  to demonstrate a BLAB server
 *  Bind, Listen, Accept, Begin
 */

//includes
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

//prototypes
void error(char*);


int main() {
	//BIND
	int listener_d = socket(PF_INET, SOCK_STREAM, 0);
	if (listener_d == -1)
		error("Can't open socket");

	//port meaning “Internet port 30000.
	struct sockaddr_in name;
		name.sin_family = PF_INET;
	name.sin_port = (in_port_t) htons(30000);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	int c = bind(listener_d, (struct sockaddr *) &name, sizeof(name));
	if (c == -1)
		error("Can't bind to socket");
	//LISTEN
	if (listen(listener_d, 10) == -1)
		error("Can't listen");
	//ACCEPT
	struct sockaddr_storage client_addr;
	//client_addr will store details about the client who’s just connected.
	unsigned int address_size = sizeof(client_addr);
	int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
	if (connect_d == -1)
		error("Can't open secondary socket");
	//BEGIN to talk
	char *msg = "Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n> ";
	if (send(connect_d, msg, strlen(msg), 0) == -1)
		error("send");

}

void error(char* msg) {
	fprintf(stderr, "%s, %s\n", msg, strerror(errno));
	exit(1);
}
