#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "psim.h"
#include "init.h"
#include "display.h"
#include "proc.h"
#include "util.h"

struct universe uverse;

int main() {
	srand(time(NULL));
	
	int bytes = init_uverse(&uverse, 10);
	printf("Allocated %d bytes\n\n", bytes);
	
	struct particle p;
	init_particle(&p);
	
	p.mass = 2.0;
	
	p.charge = 5.0;
	random_pos(&p.cstate, 20);
	add_particle(&uverse, &p);
	
	p.charge = -5.0;
	random_pos(&p.cstate, 20);
	add_particle(&uverse, &p);
	
	char c;
	while(c != 'q') {
		system("clear");
		display_uverse(uverse, 0);
		
		printf("\n# ");
		c = getchar();
		
		switch(c) {
			case 'a':
				add_particle(&uverse, &p);
				break;
				
			case 'r':
				random_pos(&p.cstate, 10);
				break;
		}		
		
		advance_state(&uverse);
	}
	
	destroy_uverse(&uverse);
	return 0;
}