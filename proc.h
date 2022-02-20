#ifndef PROC_INC
#define PROC_INC

#include "psim.h"

struct vector coll_forces(struct particle p);
void advance_state(struct universe* uverse);

#endif