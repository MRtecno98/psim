#ifndef INIT_INC
#define INIT_INC

#include "psim.h"

const struct vector vc_zero;
const struct vector vc_one;
const struct state st_zero;

int init_uverse(struct universe*, int pcount);
void destroy_uverse(struct universe*);

void init_particle(struct particle*);
void add_particle(struct universe*, struct particle*);
void random_pos(struct state*, int varia);

void set_force(int slot, struct particle*, struct vector);

#endif