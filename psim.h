#ifndef PSIM_INC
#define PSIM_INC

#define TIME_DELTA 1
#define REAL_DELTA 1

#define MAX_FORCES 10

struct vector {
	double x, y;
};

struct state {
	struct vector pos, vel, acc;
};

struct particle {
	struct vector forces[MAX_FORCES];
	
	double mass;
	double charge;
	
	struct state cstate;
};

struct universe {
	int pcount;
	int mpcount;
	long instant;
	struct particle* particles;
};

#endif
