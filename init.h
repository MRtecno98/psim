#ifndef INIT_INC
#define INIT_INC

#include "psim.h"

int init_uverse(struct universe*, int pcount);
void destroy_uverse(struct universe*);

void add_particle(struct universe*, struct particle*);

#endif