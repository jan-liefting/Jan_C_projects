/*
 * main.c
 *
 *  Created on: Jul 27, 2019
 *      Author: jan
 *
 *  Example of the use of exec()
 *
 *  List functions; attributes are passed as list of strings:
 *  execl();
 *  execlp(); same as execl(), but with search on the path
 *  execle() or execlpe(); with enviroment variables passed as array of strings
 *
 *
 *  Array functions; attributes are passed as array (of strings)
 *  execv();
 *  execvp(); same as execv(), but with search om the path
 *  execve() or execvpe(); with environment variables passed as array of strings
 *
 */

// includes
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main(){
	if(execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1)
		if(execlp("ipconfig", "ipconfig", NULL) == -1){
			fprintf(stderr, "Cannot run ipconfig: %s", strerror(errno));
			return 1;
		}
		return 0;
}
