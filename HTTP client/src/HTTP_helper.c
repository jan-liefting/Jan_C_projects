/*
 * HTTP_helper.c
 *
 * has functions to be used with the HTTP protocol
 *
 *  Created on: Aug 14, 2019
 *      Author: jan
 */

// includes
#include "HTTP_helper.h"

/**
 * Accept a well-formed URL (e.g. http://www.company.com/index.html) and return
 * pointers to the host part and the path part. Note that this function
 * modifies the uri itself as well. It returns 0 on success, -1 if the URL is
 * found to be malformed in any way.
 */
int parse_url(char *uri, char **host, char **path)
{
	char *pos;

	pos = strstr(uri, "//");

	if(!pos)
		return -1;

	*host = pos + 2;

	pos = strchr(*host, '/');

	if(!pos)
		*path = NULL;

	else
	{
		*pos = '\0';
		*path = pos + 1;
	}

	return 0;
}

/**
 * Format and send an HTTP get command. The return value will be 0
 * on success, -1 on failure, with errno set appropriately. The caller
 * must then retrieve the response.
 */
int http_get(int connection, const char *path, const char *host)
{
	static char get_command[MAX_GET_COMMAND];

	sprintf(get_command, "GET /%s HTTP/1.1\r\n", path);

	printf("%s%s",now(), get_command);

	if(send(connection, get_command, strlen(get_command), 0) == -1)
		return -1;

	sprintf(get_command, "Host: %s\r\n", host);

	//printf("%s",get_command);

	if(send(connection, get_command, strlen(get_command), 0) == -1)
		return -1;

	sprintf(get_command, "Connection: close\r\n\r\n");

	//printf("%s",get_command);

	if(send(connection, get_command, strlen(get_command), 0) == -1)
		return -1;

	return 0;
}

/**
 * Receive all data available on a connection and dump it to stdout
 */
void display_result(int connection)
{
	int received = 0;

	static char recv_buf[BUFFER_SIZE + 1];

	while((received = recv(connection, recv_buf, BUFFER_SIZE, 0)) > 0)
	{
		recv_buf[received] = '\0';

		printf("%s", recv_buf);
	}

	printf("\n");
}
