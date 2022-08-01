#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

typedef struct 
{
	shape_t super;
	int radius;
}circle_t;

void Circle_Init(circle_t* circ);

#endif
