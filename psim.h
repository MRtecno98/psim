#ifndef PSIM_INC
#define PSIM_INC

#define TIME_DELTA 1
#define REAL_DELTA 1

struct vector {
	double x, y;
};

struct state {
	struct vector pos, vel, acc;
};

struct particle {
	int fcount;
	struct vector forces[10];
	
	double mass;
	
	struct state cstate;
};

struct universe {
	int pcount;
	int mpcount;
	struct particle* particles;
};

#endif
