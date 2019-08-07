/*
 * helper.c
 *
 *  Created on: Dec 31, 2018
 *      Author: jan
 *
 *	helper.c consist of souce code for the Internet
 *	helper functions
 */


#include "helper.h"

/*
 * error prints an error message to the stderr
 */
void error(char* msg) {
	fprintf(stderr, "%s, %s\n", msg, strerror(errno));
	exit(1);
}

/*
 * read_in reads characters from the socket until we encounter /n
 */
int read_in(int socket, char *buf, int len){
	char *s = buf;
	int slen = len;
	int c = recv(socket, s, slen, 0);
	while ((c > 0) && (s[c-1] != '\n')) {
		s += c; slen -= c;
		c = recv(socket, s, slen, 0);
	}
	if (c < 0)
		return c;
	else if (c == 0)
		buf[0] = '\0';
	else
		s[c-1]='\0';
	return len - slen;
}

/*
 * open_listener creates a socket
 */
int open_listener_socket(){
	int s = socket(PF_INET, SOCK_STREAM, 0);
	if (s == -1)
		error("Can't open socket");
	return s;
}

/*
 * open_socket opens a socket based on a host url
 */
int open_socket(char *host, char *port) {
	struct addrinfo *res;
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = PF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	if (getaddrinfo(host, port, &hints, &res) == -1)
		error("Can't resolve the address");
	int d_sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (d_sock == -1)
		error("Can't open socket");
	int c = connect(d_sock, res->ai_addr, res->ai_addrlen);
	freeaddrinfo(res);
	if (c == -1)
		error("Can't connect to socket");
	return d_sock;
}

/*
 * bind_to_port binds to port 30000
 */
void bind_to_port(int socket, int port){
	struct sockaddr_in name;
	name.sin_family = PF_INET;
	name.sin_port = (in_port_t)htons(port);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	int reuse = 1;
	if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
		error("Can't set the reuse option on the socket");
	int c = bind (socket, (struct sockaddr *) &name, sizeof(name));
	if (c == -1)
		error("Can't bind to socket");
}

/*
 * say sends a string to socket
 */
int say(int socket, char *s){
	int result = send(socket, s, strlen(s), 0);
	// You won’t want to stop the server if
	// there’s just a problem with one client.
	if (result == -1)
	fprintf(stderr, "%s: %s\n", "Error talking to the client", strerror(errno));
	return result;
}




