#include "map_printer_ordinary.h"
#include <stdio.h>

///@brief Prints a map points shifted by 2 on the x axis
void MapPrinter_Shifter_Print(point_t *points, size_t points_count)
{
	printf("point\tX\tY\n");
	for (size_t p = 0; p < points_count; p++)
	{
		printf("%lu\t%d\t%d\n", p, points[p].x + 2, points[p].y);
	}
}