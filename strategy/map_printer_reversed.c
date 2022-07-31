#include "map_printer_ordinary.h"
#include <stdio.h>

///@brief Prints map points in a reversed order
void MapPrinter_Reversed_Print(point_t *points, size_t points_count)
{
	printf("point\tX\tY\n");
	for (int p = points_count - 1; p >= 0; p--)
	{
		printf("%lu\t%d\t%d\n", p, points[p].x, points[p].y);
	}
}