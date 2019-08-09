//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//compare functions
int compare_scores_desc(const void* a, const void* b);

int compare_names(const void*, const void*);

int main() {
	int scores[] = { 543, 323, 32, 554, 11, 3, 112 };
	int i;
	qsort(scores, 7, sizeof(int), compare_scores_desc);
	puts("These are the scores in order:");
	for (i = 0; i < 7; i++) {
		printf("Score = %i\n", scores[i]);
	}
	char *names[] = { "Karen", "Mark", "Brett", "Molly" };
	qsort(names, 4, sizeof(char*), compare_names);
	puts("These are the names in order:");
	for (i = 0; i < 4; i++) {
		printf("%s\n", names[i]);
	}
	return 0;
}

int compare_scores_desc(const void* a, const void* b){
	return *(int*)a-*(int*)b;
}

int compare_names(const void* a, const void* b){
	return strcmp(*(char**)a, *(char**)b);
}
//
// char* names[index];
// index=0;  *(names[0]) = "Karen/0"
// index=1;  *(names[1]) = "Mark/0"
//
// a = ptr;  *prt = names[i];  names[i] heeft type char*;  dus a heeft type char**;
// b = ptr;  *prt = names[j];  names[j] heeft type char*;  dus a heeft type char**;
//
// a = ptr --> index i --> "Karen/0"
// (char**) a; --> (char*) index i --> "Karen/0"
//
// Bij een type const void* wat een generieke pointer is, moet je eerst de variabale casten naar
// het juiste type voordat je deze kan gebruiken!!
//
