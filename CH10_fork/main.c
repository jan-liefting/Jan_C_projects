/*
 * main.c
 *
 *  Created on: Aug 19, 2018
 *      Author: jan
 */

//includes

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]) {

	char *feeds[] = { "http://feeds.bbci.co.uk/news/rss.xml" };
	int times = 1;
	char *phrase = argv[1];
	int i;
	for (i = 0; i < times; i++) {
		char var[255];
		sprintf(var, "RSS_FEED=%s", feeds[i]);
		char *vars[] = { var, NULL };

//		pid_t pid = fork();
//		if (pid == -1) { //there is an issue with the forking
//			fprintf(stderr, "Can't fork the process %s\n", strerror(errno));
//			return 1;
//		}
//		if (!pid) { // this is executed by the child process only
					// change the child process by changing it to Python
			fprintf(stdout,"Looking for: %s\n", phrase);
			if (execle("/usr/bin/python", "/usr/bin/python", "/home/jan/Desktop/rssgossip.py",
					phrase, NULL, vars) == -1) {
				fprintf(stderr, "Can't start Python %s\n", strerror(errno));
				return 1;
//			}
		}
	}
}
