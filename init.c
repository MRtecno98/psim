#include "psim.h"
#include "init.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>

const struct vector vc_zero = {0.0, 0.0};
const struct vector vc_one = {1.0, 1.0};

const struct state st_zero = {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}};

int init_uverse(struct universe* uverse, int mpcount) {
	int bytes = sizeof(struct particle) * mpcount;
	
	uverse->instant = 0;
	uverse->pcount = 0;
	uverse->mpcount = mpcount;
	uverse->particles = realloc(uverse->particles, bytes);
	
	return bytes;
}

void destroy_uverse(struct universe* uverse) {
	init_uverse(uverse, 0);
}

void init_particle(struct particle* p) {
	p->mass = 0.0;
	p->charge = 0.0;
	
	for(int i = 0; i < MAX_FORCES; i++)
		p->forces[i] = vc_zero;
	
	p->cstate = st_zero;
}

void add_particle(struct universe* uverse, struct particle* p) {
	if(uverse->pcount == uverse->mpcount) {
		fprintf(stderr, "\nERROR: Max particle count reached\n");
		exit(1);
	}
	
	uverse->pcount++;
	uverse->particles[uverse->pcount - 1] = *p;
}

void random_pos(struct state* s, int varia) {
	s->pos = randvec(varia);
}

void set_force(int slot, struct particle* p, struct vector force) {
	p->forces[slot] = force;
}