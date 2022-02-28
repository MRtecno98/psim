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
	random_pos(&p.cstate, 50);
	add_particle(&uverse, &p);
	
	p.charge = -5.0;
	random_pos(&p.cstate, 50);
	add_particle(&uverse, &p);
	
	char c = '\n', lc;
	while(c != 'q') {
		system("clear");
		display_uverse(uverse, 0);
		
		printf("\n# ");
		do {
			lc = c;
			c = getchar();
		} while(c == '\n' && lc != '\n');
		
		switch(c) {
			case 'a':
				add_particle(&uverse, &p);
				break;
				
			case 'r':
				random_pos(&p.cstate, 50);
				break;
				
			case 'm':
				scanf("%lf", &p.mass);
				break;
				
			case 's': {
				long steps;
				scanf("%ld", &steps);
				printf("Processing fast-forward...\n");
				
				for(int i = 0; i < steps; i++) {
					print_progress(i, steps, 20);
					advance_state(&uverse);
				}
				
				break;
			}
				
			case '\n':
				advance_state(&uverse);
				break;
		}
	}
	
	destroy_uverse(&uverse);
	return 0;
}