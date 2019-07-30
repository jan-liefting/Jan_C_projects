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
#include <sys/wait.h>
#include "err.h"

int main(int argc, char* argv[]) {
	char *feeds[] = { "http://feeds.bbci.co.uk/news/rss.xml",
					  "http://feeds.nos.nl/nosnieuwsalgemeen" };
	char *search_phrase = argv[1];
	FILE *f = fopen("stories.txt", "w");
	enum feed_select {FIRST, SECOND}; // FIRST == 0; SECOND == 1

	char temp[255];
	sprintf(temp, "RSS_FEED=%s", feeds[FIRST]);
	char *vars[] = { temp, NULL };

	pid_t pid = fork(); // start new child process
	if (pid == -1) // there is an issue with the forking
		error("Can't fork the process");

	if (!pid) { // this is executed by the child process only
				// change the child process by changing it to Python
		if (dup2(fileno(f), 1) == -1) // redirect stdout(1) to FILE f
			error("Can't redirect the standard output to the file");
		fprintf(stderr, "Child process looking for: %s on %s\n", search_phrase, feeds[FIRST]);
		// change the child process to Python
		if (execle("/usr/bin/python", "usr/bin/python",
				"/home/jan/Desktop/rssgossip.py", search_phrase, NULL, vars) == -1)
			error("Can't start Python/run the script");
		// when the execle call is successful, this code is never executed by the child
	}

	// code that let the parent wait for the child process to finish
	int pid_status;
	fprintf(stderr, "Parent proces waiting for the child to finish..\n");
	if(waitpid(pid, &pid_status, 0) == -1)
		error("Error waiting for the child process");
	fprintf(stderr, "Finished! PID is: %x, PID status is: %x, WEXITSTATUS is: %x\n", pid, pid_status, WEXITSTATUS(pid_status));
	if (WEXITSTATUS(pid_status))
	//If the exit status is not zero
		puts("Error status non-zero");

	return 0;
}

