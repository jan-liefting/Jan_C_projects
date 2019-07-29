/*
 * ch10_redirect_IO.c
 *
 *  Created on: Jul 28, 2019
 *      Author: jan
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "err.h"


int main(int argc, char* argv[]){
	char *feeds[] = { "http://feeds.bbci.co.uk/news/rss.xml",
			"http://feeds.nos.nl/nosnieuwsalgemeen" };
	int times = 1;
	char *phrase = argv[1];
	int i;
	FILE *f = fopen("stories.txt", "w");

	for (i = 0; i < times; i++) {
		char var[255];
		sprintf(var, "RSS_FEED=%s", feeds[0]);
		char *vars[] = { var, NULL };

		pid_t pid = fork();
		if (pid == -1) //there is an issue with the forking
			error("Can't fork the process");

		if (!pid) { // this is executed by the child process only
					// change the child process by changing it to Python
			if(dup2(fileno(f), 1) == -1) // redirect stdout(1) to FILE f
				error("Can't redirect the standard output to the file");
			fprintf(stdout, "Looking for: %s on %s\n", phrase, feeds[0]);
			if (execle("/usr/bin/python", "usr/bin/python",
					"/home/jan/Desktop/rssgossip.py", phrase, NULL, vars)
					== -1)
			error("Can't start Python/run the script");
		}
	}
	//	while(1);
	return 0;
}

