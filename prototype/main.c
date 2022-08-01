#include "rectangle.h"
#include "circle.h"

int main(void)
{
	rectangle_t r1;
	Rectangle_Init(&r1);
	r1.super.x = 1;
	r1.super.y = 1;
	r1.super.color = "Red";
	r1.height = 10;
	r1.width = 20;

	circle_t c1;
	Circle_Init(&c1);
	c1.super.color = "Black";
	c1.radius = 5;

	shape_t *shapes_array[4];
	shapes_array[0] = (shape_t *)&r1;
	shapes_array[1] = (shape_t *)&c1;
	/*
	 * 
	 * 
	 * 
	 * 
	 */
	shapes_array[2] = Shape_Clone(shapes_array[1]);
	shapes_array[3] = Shape_Clone(shapes_array[0]);

	for (int i = 0; i < 4; i++)
		Shape_Draw(shapes_array[i]);
}