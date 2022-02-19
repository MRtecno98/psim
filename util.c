#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* repeat(char c, int times) {
	char* s = calloc(times, sizeof(c));
	for(int i = 0; i < times; i++) s[i] = c;
	
	return s;
}

char* repeats(char* s, int times) {
	const int len = strlen(s);
    const int bytes = (len * times) + 1;
	
	char *r = malloc(bytes);
	for(int i = 0; i < bytes; i++) r[i] = s[i % len];
    
    r[bytes - 1] = '\0';
	
	return r;
}

void printr(char c, int times) {
	char* s = repeat(c, times);
	printf("%s", s);
	free(s);
}

void printrs(char* s, int times) {
	char* r = repeats(s, times);
	printf("%s", r);
	free(r);
}

