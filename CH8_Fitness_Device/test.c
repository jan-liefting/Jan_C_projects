/*
 * test.c
 *
 *  Created on: Aug 15, 2018
 *      Author: jan
 *
 *      Step 1: place hfcal.h file in /usr/local/include (done)
 *      Step 2: make static library and place this in /usr/local/lib (done)
 *
 */

//includes
#include <stdio.h>
#include "hfcal.h"

int main() {
	display_calories(115.2, 11.3, 0.79);
	return 0;
}

