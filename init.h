#ifndef INIT_INC
#define INIT_INC

#include "psim.h"

int init_uverse(struct universe*, int pcount);
void destroy_uverse(struct universe*);

void init_particle(struct particle*);
void add_particle(struct universe*, struct particle*);

void add_const_force(int slot, struct particle*, struct vector);

#endif