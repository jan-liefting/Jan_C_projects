/*
 * main.c
 *
 *  Created on: Aug 20, 2018
 *      Author: jan
 */

//include files
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

void error(char*);
void open_url(char*);

int main(int argc, char *argv[]) {

	char *feeds[] = { "http://feeds.bbci.co.uk/news/rss.xml",
			"http://rss.cnn.com/rss/cnn_topstories.rss" };
	char *scriptname = "/home/jan/Desktop/rssgossip.py";
	char *python = "/usr/bin/python";
	int times = 2;
	char *phrase = argv[1];
	int i;
	FILE *f = fopen("stories.txt", "w");
	pid_t pid;
	pid_t pidArray[times];
	if (!f)
		error("Can't open stories.txt");

	for (i = 0; i < times; i++) {
		char var[255];
		sprintf(var, "RSS_FEED=%s", feeds[i]);
		char *vars[] = { var, NULL };
		int fd[2];
		if (pipe(fd) == -1) {
			error("Can't create the pipe");
		}

		pid = fork();
		/* fork()
		 function returns 0 to the child process, and it will return a
		 nonzero value to the parent process
		 */

		if (pid == -1) { //there is an issue with the forking
			error("Can't fork the process %s\n");
			return 1;
		}
		if (!pid) { // this is executed by the child process only

//			if (dup2(fileno(f), 1) == -1) //redirect standard output to file f
//				error("Can't redirect the Standard Output");
			close(fd[0]); //close the read part of the pipe
			if (dup2(fd[1], 1) == -1) //redirect the child standard output to the pipe write
				error("Can't redirect the Standard Output of the child process");
			fprintf(stderr, "Child process runs..Looking for: %s\n", phrase);
			fprintf(stderr, "at: %s\n", var);
			fprintf(stderr, "with script: %s\n", scriptname);
			// transfer process over to python
			if (execle(python, python, scriptname, "-u", phrase, NULL, vars) == -1)
				error("Can't run script %s\n");

			// this section is never executed by the child
		} else { //executed by the parent
			if (dup2(fd[0], 0) == -1) //redirect the parent standard input to the pipe output
				error("Can't redirect the Standard Output of the child process");
			close(fd[1]); //close the write part of the pipe
			pidArray[i] = pid; // store the pid of the child process
			fprintf(stderr, "PID: %i\n", pidArray[i]);
			//process the stream from the child process
			char line[255];
			while (fgets(line, 255, stdin)) {
				fprintf(f,"%s", line);

				if (line[0] == '\t'){
					open_url(line + 1); //url start with a [tab]
				}
			}
		}
	}
	int pid_status[times];
	for (int i = 0; i < times; i++) {
		if (waitpid(pidArray[i], pid_status + i, 0) == -1){
			error("Error waiting for child process");
			return 1;
		}
	}
	return 0; //nice
}

void error(char* msg) {
	fprintf(stderr, "%s, %s\n", msg, strerror(errno));
	exit(1);
}

void open_url(char *url) {
	pid_t pid;

	pid = fork();
	/* fork()
	 function returns 0 to the child process, and it will return a
	 nonzero value to the parent process
	 */

	if (pid == -1) //there is an issue with the forking
		error("Can't fork the process %s\n");

	if (!pid) // this is executed by the child process only
		if (execl("x-www-browser", "x-www-browser", url, NULL) == -1)
			error("Can't run browser %s\n");
			// the child never arrives here!
	return;
}
