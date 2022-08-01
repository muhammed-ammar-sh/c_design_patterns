#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

typedef struct 
{
	shape_t super;
	int width;
	int height;
}rectangle_t;

void Rectangle_Init(rectangle_t* rect);

#endif
