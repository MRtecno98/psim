#include "proc.h"
#include "psim.h"
#include "util.h"

#include <math.h>

struct vector coll_forces(struct particle p) {
	struct vector res = {0.0, 0.0};
	for(int i = 0; i < MAX_FORCES; i++) {
		struct vector force = p.forces[i];
		
		res = vsum(res, force);
	}
	
	return res;
}

void advance_state(struct universe* uverse) {
	// struct universe before = *uverse;
	
	for(int i = 0; i < uverse->pcount; i++) {
		struct particle* p = &uverse->particles[i];
		struct vector force = coll_forces(*p);
		
		struct state nstate = p->cstate;
		
		nstate.acc = vdiv(force, p->mass); // F = ma => a = F/m
		
		// a(t) = a0
		// v(t) = v0 + a0t
		// s(t) = s0 + v0t + 1/2a0t^2
		nstate.vel = vsum(p->cstate.vel, vmul(nstate.acc, TIME_DELTA));
		nstate.pos = vsum3(p->cstate.pos, vmul(p->cstate.vel, TIME_DELTA),
						  vdiv(vmul(nstate.acc, pow(TIME_DELTA, 2)), 2));
						  
		p->cstate = nstate;
	}
}