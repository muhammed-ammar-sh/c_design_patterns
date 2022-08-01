#include "shape.h"
#include <stddef.h>

void Shape_Init(shape_t *shape)
{
	if (shape)
	{
		shape->methods = NULL;
		shape->x = 0;
		shape->y = 0;
		shape->color = "";
	}
}

