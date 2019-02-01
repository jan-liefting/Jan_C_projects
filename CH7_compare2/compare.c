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