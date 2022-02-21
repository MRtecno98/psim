#ifndef UTIL_INC
#define UTIL_INC

#include <stdbool.h>

#include "psim.h"

char* repeat(char c, int times);
char* repeats(char* s, int times);

void printr(char c, int times);
void printrs(char* s, int times);

struct vector vsum3(struct vector a, struct vector b, struct vector c);
struct vector vsum(struct vector a, struct vector b);
struct vector vdiv(struct vector v, double q);
struct vector vmul(struct vector v, double f);
struct vector vdiff(struct vector, struct vector);

bool veq(struct vector, struct vector);

double dist(struct vector, struct vector);
double dist_x(struct vector a, struct vector b);
double dist_y(struct vector a, struct vector b);

double angcoeff(struct vector a, struct vector b);

struct vector randvec(int varia);

#endif