#include <stdio.h>
#include <stdlib.h>

#include "psim.h"
#include "init.h"
#include "display.h"

struct universe uverse;

int main() {
	int bytes = init_uverse(&uverse, 10);
	printf("Allocated %d bytes\n\n", bytes);
	
	struct particle p;
	p.mass = 2.0;
	p.fcount = 0;
	p.cstate.pos.x = 5.0;
	p.cstate.pos.y = 10.0;
	
	add_particle(&uverse, &p);
	
	display_uverse(uverse, 0);
	
	destroy_uverse(&uverse);
	return 0;
}