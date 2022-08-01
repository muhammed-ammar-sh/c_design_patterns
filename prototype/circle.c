#include "circle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void Circle_Draw(shape_t *shape);
static shape_t *Circle_Clone(shape_t *shape);

static const shape_methods_t Circle_methods = {
	.draw = Circle_Draw,
	.clone = Circle_Clone,
};

void Circle_Init(circle_t *circ)
{
	if (circ)
	{
		Shape_Init(&circ->super);
		circ->super.methods = &Circle_methods;
		circ->radius = 0;
	}
}

static void Circle_Draw(shape_t *shape)
{
	if (shape)
	{
		circle_t *circ = (circle_t *)shape;
		printf("Drawing Circle shape : \n");
		printf("\tX = %d\n", circ->super.x);
		printf("\tY = %d\n", circ->super.y);
		printf("\tColor = %s\n", circ->super.color);
		printf("\tRadius = %d\n", circ->radius);
	}
}

static shape_t *Circle_Clone(shape_t *shape)
{
	if (shape)
	{
		circle_t *circ = (circle_t *)shape;
		circle_t *clone = malloc(sizeof(circle_t));
		if (clone)
		{
			memcpy(clone, circ, sizeof(circle_t));
			// or
			// clone->height = circ->height;
			// clone->width = circ->width;
			// clone->super.x = circ->super.x;
			// ...
		}
		return (shape_t *)clone;
	}
}