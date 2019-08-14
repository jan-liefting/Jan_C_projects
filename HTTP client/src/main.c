/*
 * main.c
 *
 *  Created on: Aug 10, 2019
 *      Author: jan
 */
// defines
#define HTTP_PORT 80

// includes
/**
 * This test utility does simple (non-encrypted) HTTP.
 */
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#include "HTTP_helper.h"
#include "Log.h"

/**
 * Simple command-line HTTP client.Chapter 1
 */
int main(int argc, char *argv[])
{
	int client_connection;
	char *host, *path;
	struct hostent *host_name;
	struct sockaddr_in host_address;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s: <URL>\n", argv[0]);
		return 1;
	}
	if(parse_url(argv[1], &host, &path) == -1)
	{
		fprintf(stderr, "Error - malformed URL ‘%s’.\n", argv[1]);
		return 1;
	}
	printf("Connecting to host ‘%s’\n", host);
	printf("Looking for file ‘%s‘\n", path);

	// Step 1: open a socket connection on http port with the destination host.
	client_connection = socket(PF_INET, SOCK_STREAM, 0);
	if(!client_connection)
	{
		perror("Unable to create local socket");
		return 2;
	}
	host_name = gethostbyname(host);
	if(!host_name)
	{
		perror("Error in name resolution");
		return 3;
	}

	host_address.sin_family = AF_INET;
	host_address.sin_port = htons(HTTP_PORT);
	memcpy(&host_address.sin_addr, host_name->h_addr_list[0],
			sizeof(struct in_addr));
	if(connect(client_connection, (struct sockaddr *)&host_address,
			sizeof(host_address)) == -1)
	{
		perror("Unable to connect to host");
		return 4;
	}
	printf("Retrieving document: ‘%s’\n", path);

	http_get(client_connection, path, host);
	display_result(client_connection);
	printf("Shutting down.\n");
	if(close(client_connection) == -1)
	{
		perror("Error closing client connection");
		return 5;
	}

	return 0;
}
