#include "proc.h"
#include "psim.h"
#include "util.h"
#include "init.h"

#include <math.h>
#include <stdio.h>

#define GRAV_CONST 1.0
#define CHRG_CONST 1.0

struct vector coll_forces(struct particle p) {
	struct vector res = {0.0, 0.0};
	for(int i = 0; i < MAX_FORCES; i++) {
		struct vector force = p.forces[i];
		
		res = vsum(res, force);
	}
	
	return res;
}

typedef double (*force_coeff_fn)(struct particle, struct particle);
struct vector calc_func_force(struct particle p, struct universe* uverse, force_coeff_fn coeff) {
	struct vector res = vc_zero;
	for(int i = 0; i < uverse->pcount; i++) {
		struct particle t = uverse->particles[i];
		
		// F = coeff / d^2
		
		struct vector ppos = p.cstate.pos;
		struct vector tpos = t.cstate.pos;
		
		double d = dist(ppos, tpos);
		if(d == 0) continue;
		
		double lforce = coeff(p, t) / pow(d, 2);
		double angc = angcoeff(ppos, tpos);
		double ang = atan(angc);
		
		struct vector force;
		force.x = (dist_x(ppos, tpos) > 0 ? 1 : -1) * lforce * cos(ang);
		force.y = (dist_y(ppos, tpos) > 0 ? 1 : -1) * lforce * sin(ang);
		
		res = vsum(res, force);
	}
	
	return res;
}

double c_gravity(struct particle p, struct particle t) {
	return GRAV_CONST * p.mass * p.mass;
}

double c_electr(struct particle p, struct particle t) {
	return CHRG_CONST * p.charge * p.charge;
}

void advance_state(struct universe* uverse) {
	// struct universe before = *uverse;
	
	for(int i = 0; i < uverse->pcount; i++) {
		struct particle* p = &uverse->particles[i];
		
		set_force(8, p, calc_func_force(*p, uverse, &c_electr));
		set_force(9, p, calc_func_force(*p, uverse, &c_gravity));
		
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
