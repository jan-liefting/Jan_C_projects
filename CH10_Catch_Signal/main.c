/*
 * Catch_signal demonstrates OS signals
 *
 */

// defines
#define NULL 0

// includes
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

// handler
void diediedie(int sig) {
	char signal[80];
	sprintf(signal, "\nGoodbye cruel world....\nSignal = %i\n", sig);
	puts(signal);
	exit(1);
}

// register the handler
int catch_signal(int sig, void (*handler)(int)) {
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig, &action, NULL);
}

int main() {
	// register the handler with the OS
	if (catch_signal(SIGINT, diediedie) == -1) {
		fprintf(stderr, "Can't map the handler");
		exit(2);
	}
	char name[30];
	printf("Enter your name: ");
	fgets(name, 30, stdin);
	printf("Hello %s\n", name);
	return 0;
}
