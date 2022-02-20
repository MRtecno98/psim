#include <stdio.h>
#include <stdlib.h>

#include "psim.h"
#include "init.h"
#include "display.h"
#include "proc.h"

struct universe uverse;

int main() {
	int bytes = init_uverse(&uverse, 10);
	printf("Allocated %d bytes\n\n", bytes);
	
	struct particle p;
	init_particle(&p);
	
	p.mass = 2.0;
	
	struct vector force = {1, 0.5};
	add_const_force(0, &p, force);
	
	add_particle(&uverse, &p);
	
	while(true) {
		display_uverse(uverse, 0);
		
		getchar();
		advance_state(&uverse);
	}
	
	destroy_uverse(&uverse);
	return 0;
}