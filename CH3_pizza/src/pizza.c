/*
 * pizza.c
 *
 *  Created on: Apr 1, 2019
 *      Author: jan
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 *
 */
int main(int argc, char** argv) {

	char *delivery = "";
	int thick = 0;
	int count = 0;
	char ch;

	while ((ch = getopt(argc, argv, "d:t")) != EOF)
		switch (ch) {
		case 'd':
			delivery = optarg;
			break;
		case 't':
			thick = 1;
			break;
		default:
			fprintf(stderr, "Unknown option: '%s'\n", optarg);
			return 0;
		}

	argc -= optind;
	argv += optind;

	if (thick)
		puts("Thick crust.");
	if (delivery[0])
		printf("To be delivered %s.\n", delivery);

	puts("Ingredients:");

	for (count = 0; count < argc; count++)
		puts(argv[count]);


	return (EXIT_SUCCESS);
}


