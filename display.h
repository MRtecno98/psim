#ifndef DISPLAY_INC
#define DISPLAY_INC

#include "psim.h"
#include <stdarg.h>
#include <stdbool.h>

#define MAX_LINE 80
#define INDENT_SIZE 4

void vprintd(char* s, int indent, bool pad, va_list args);
void vprintdln(char* s, int indent, bool pad, va_list args);

void printd(char *s, int indent, bool pad, ...);
void printdln(char *s, int indent, bool pad, ...);

void display_uverse(struct universe, int indent);
void display_particle(struct particle*, int indent);
void display_vector(struct vector, int indent);

#endif