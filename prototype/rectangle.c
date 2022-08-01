#include "rectangle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void Rectangle_Draw(shape_t* shape);
static shape_t* Rectangle_Clone(shape_t* shape);

static const shape_methods_t rectangle_methods = {
	.draw = Rectangle_Draw,
	.clone = Rectangle_Clone,
};

void Rectangle_Init(rectangle_t* rect)
{
	if (rect)
	{
		Shape_Init(&rect->super);
		rect->super.methods = &rectangle_methods;
		rect->height = 0;
		rect->width = 0;
	}
}

static void Rectangle_Draw(shape_t* shape)
{
	if (shape)
	{
		rectangle_t* rect = (rectangle_t*) shape;
		printf("Drawing rectangle shape : \n");
		printf("\tX = %d\n", rect->super.x);
		printf("\tY = %d\n", rect->super.y);
		printf("\tColor = %s\n", rect->super.color);
		printf("\tHeight = %d\n", rect->height);
		printf("\tWidth = %d\n", rect->width);
	}
}

static shape_t* Rectangle_Clone(shape_t* shape)
{
	if (shape)
	{
		rectangle_t* rect = (rectangle_t*) shape;
		rectangle_t* clone = malloc(sizeof(rectangle_t));
		if (clone)
		{
			memcpy(clone, rect, sizeof(rectangle_t));
			// or
			// clone->height = rect->height;
			// clone->width = rect->width;
			// clone->super.x = rect->super.x;
			// ...
		}
		return (shape_t*)clone;
	}
}
