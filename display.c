#include "psim.h"
#include "util.h"
#include "display.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vprintd(char* format, int indent, bool pad, va_list args) {
	const int space = indent * INDENT_SIZE;
	
	char* s;
	int size = vsnprintf(s, 0, format, args) + 1;
	
	s = malloc(size);
	vsnprintf(s, size, format, args);
	
	printr(' ', space);
	printf("%s", s);
	if(pad) printr('-', MAX_LINE - (strlen(s) + space));
	
	free(s);
}

void vprintdln(char* format, int indent, bool pad, va_list args) {
	vprintd(format, indent, pad, args);
	printf("\n");
}

void printd(char* format, int indent, bool pad, ...) {
	va_list args;
	va_start(args, pad);
	
	vprintd(format, indent, pad, args);
	
	va_end(args);
}

void printdln(char* format, int indent, bool pad, ...) {
	va_list args;
	va_start(args, pad);
	
	vprintdln(format, indent, pad, args);
	
	va_end(args);
}

void display_uverse(struct universe uverse, int indent) {
	printdln("Universe ", indent, true);
	
	for(int i = 0; i < uverse.pcount; i++) {
		display_particle(&uverse.particles[i], indent + 1);
		printf("\n");
	}
}

void display_particle(struct particle* p, int indent) {
	printdln("Particle ", indent, true);
	
	printdln("Mass: %.2f", indent + 1, false, p->mass);
	printf("\n");
	
	printdln("Forces: %d", indent + 1, false, p->fcount);
	
	for(int i = 0; i < p->fcount; i++)
		display_vector(p->forces[i], indent + 2);
	
	printf("\n");
	
	printd("Position\t: ", indent + 1, false);
	display_vector(p->cstate.pos, indent + 2);
	
	printd("Velocity\t: ", indent + 1, false);
	display_vector(p->cstate.vel, indent + 2);
	
	printd("Acceleration\t: ", indent + 1, false);
	display_vector(p->cstate.acc, indent + 2);
}

void display_vector(struct vector v, int indent) {
	printdln("X: %.2f Y: %.2f", indent, false, v.x, v.y);
}