#include "psim.h"
#include "util.h"
#include "init.h"
#include "display.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vprintd(char* format, int indent, bool pad, va_list args) {
	const int space = indent * INDENT_SIZE;
	
	char s[MAX_LINE * 2];
	vsnprintf(s, MAX_LINE * 2, format, args);
	
	printr(' ', space);
	printf("%s", s);
	if(pad) printr('-', MAX_LINE - (strlen(s) + space));
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
	printdln("Universe - Instant: %d ", indent, true, uverse.instant);
	
	for(int i = 0; i < uverse.pcount; i++) {
		display_particle(&uverse.particles[i], indent + 1);
		printf("\n");
	}
	
	printdln("", indent, true);
}

void display_particle(struct particle* p, int indent) {
	printdln("Particle ", indent, true);
	
	printdln("Mass: %.2f", indent + 1, false, p->mass);
	printdln("Charge: %.2f", indent + 1, false, p->charge);
	printf("\n");
	
	int c = 0;
	struct vector* forces[10];
	for(int i = 0; i < MAX_FORCES; i++) {
		if(!veq(p->forces[i], vc_zero)) {
			c++;
			forces[i] = &p->forces[i];
		} else forces[i] = NULL;
	}
		
	printdln("Forces: %d/%d", indent + 1, false, c, MAX_FORCES);
	
	for(int i = 0; i < MAX_FORCES; i++)
		if(forces[i] != NULL)
			display_vector(*forces[i], indent + 2);
	
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

void print_progress(long val, long max, int size) {
	int full = ((float) (val * size)) / max;
	
	printf("\r[ %ld / %ld ", val, max);
	for(int i = 0; i < size; i++) {
		printf(i <= full ? "#" : "-");
	}
	printf(" ]");
	
	fflush(stdout);
}