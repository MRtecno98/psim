#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

struct vector vsum3(struct vector a, struct vector b, struct vector c) {
	struct vector res;
	res.x = a.x + b.x + c.x;
	res.y = a.y + b.y + c.y;
	
	return res;
}

struct vector vsum(struct vector a, struct vector b) {
	struct vector res;
	res.x = a.x + b.x;
	res.y = a.y + b.y;
	
	return res;
}

struct vector vdiv(struct vector v, double q) {
	struct vector res;
	res.x = v.x / q;
	res.y = v.y / q;
	
	return res;
}

struct vector vmul(struct vector v, double f) {
	struct vector res;
	res.x = v.x * f;
	res.y = v.y * f;
	
	return res;
}

bool veq(struct vector a, struct vector b) {
	return a.x == b.x && a.y == b.y;
}

struct vector vdiff(struct vector a, struct vector b) {
	struct vector res;
	res.x = b.x - a.x;
	res.y = b.y - a.y;
	
	return res;
}

double dist(struct vector a, struct vector b) {
	return sqrt(pow(dist_x(a, b), 2) + pow(dist_x(a, b), 2));
}

double dist_x(struct vector a, struct vector b) {
	return b.x - a.x;
}

double dist_y(struct vector a, struct vector b) {
	return b.y - a.y;
}

double angcoeff(struct vector a, struct vector b) {
	struct vector diff = vdiff(a, b);
	return diff.y / diff.x;
}

struct vector randvec(int varia) {
	struct vector v;
	v.x = rand() % varia;
	v.y = rand() % varia;
	
	return v;
}
