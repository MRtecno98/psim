#include "psim.h"
#include "init.h"

#include <stdio.h>
#include <stdlib.h>

int init_uverse(struct universe* uverse, int mpcount) {
	int bytes = sizeof(struct particle) * mpcount;
	
	uverse->pcount = 0;
	uverse->mpcount = mpcount;
	uverse->particles = realloc(uverse->particles, bytes);
	
	return bytes;
}

void destroy_uverse(struct universe* uverse) {
	init_uverse(uverse, 0);
}

void add_particle(struct universe* uverse, struct particle* p) {
	if(uverse->pcount == uverse->mpcount) {
		fprintf(stderr, "\nERROR: Max particle count reached\n");
		exit(1);
	}
	
	uverse->pcount++;
	uverse->particles[uverse->pcount - 1] = *p;
}