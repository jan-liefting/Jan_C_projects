/*
 * main.c
 *
 *  Created on: Aug 13, 2018
 *      Author: jan
 */

//includes
#include <stdio.h>
#include <stdarg.h>

//globals
enum drink {
	MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
};

//prototypes
double total(int args, ...);
double price(enum drink);

int main() {
	printf("Price is %.2f\n", total(2, MONKEY_GLAND, MUDSLIDE));
	printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
	printf("Price is %.2f\n", total(1, ZOMBIE));

	return(1);
}

double total(int args, ...){
	double total = 0.0;
	va_list ap;
	va_start(ap, args);
	for(int i=0; i<args; i++){
		enum drink d = va_arg(ap, enum drink);
		total += price(d);
	}
	va_end(ap);

	return(total);
}

double price(enum drink d) {
	switch (d) {
	case MUDSLIDE:
		return 6.79;
	case FUZZY_NAVEL:
		return 5.31;
	case MONKEY_GLAND:
		return 4.82;
	case ZOMBIE:
		return 5.89;
	}
	return 0;
}
