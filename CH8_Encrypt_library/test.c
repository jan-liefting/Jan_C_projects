/*
 * test.c
 *
 *  Created on: Aug 13, 2018
 *      Author: jan
 */

//includes
#include <stdio.h>
#include <Encrypt.h>
#include <Checksum.h>

int main() {
	char s[] = "Speak friend and enter";
	printf("%s\n", s);
	printf("Checksum is %i\n", checksum(s));
	encrypt(s);
	printf("Encrypted to '%s'\n", s);
	printf("Checksum is %i\n", checksum(s));
	encrypt(s);
	printf("Decrypted back to '%s'\n", s);
	printf("Checksum is %i\n", checksum(s));
	return 0;
}
