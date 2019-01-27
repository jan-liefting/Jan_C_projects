/*
 * test.c
 *
 *  Created on: Aug 18, 2018
 *      Author: jan
 */

//include files
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
	//char string1[] = "/sbin/ifconfig";
	//char string2[] = "ipconfig";
//	if (execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1)
		if (execlp("ifconfig","ifconfig", NULL) == -1) {
			fprintf(stderr, "Cannot run ipconfig \n%s", strerror(errno));
			return 1;
		}
	return 0;
}
