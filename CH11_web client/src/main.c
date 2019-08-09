/*
 * main.c
 *
 *  Created on: Aug 5, 2019
 *      Author: jan
 */

// includes
//
#include "helper.h"

int main(int argc, char *argv[]){
	int d_sock = open_socket("www.jskf.nl", "80");

	char buf[255];
	sprintf(buf, "GET /index.html HTTP/1.1\r\n");
	say(d_sock, buf);
	sprintf(buf, "Host: www.jskf.nl\r\n\r\n");
	say(d_sock, buf);

	char rec[256];
	int bytesrecv = recv(d_sock, rec, 255, 0);
	// while there is more being received from the host
	while(bytesrecv){
		if(bytesrecv == -1)
			error("Can't read from the server");
		// add /0 to finalize the string
		rec[bytesrecv] = '\0';
		printf("%s", rec);
		// next
		bytesrecv = recv(d_sock, rec, 255, 0);
	}

	close(d_sock);

	return(0);
}


