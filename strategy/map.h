#ifndef MAP_H
#define MAP_H

#include <stdint.h>

typedef struct
{
	int x, y;
} point_t;

typedef void (*map_printer_t)(point_t *points, size_t points_count);

typedef struct
{
	point_t *points;
	size_t points_count;
	size_t max_points_count;
	map_printer_t printer; // In strategy pattern: instead of creating an interface with one method, 
						   // we can use function pointer directly in C to simplify the code.
} map_t;

void Map_Init(map_t *map, point_t *points_array, size_t max_points_count);
void Map_SetPrinter(map_t *map, map_printer_t printer);
void Map_Print(map_t *map);
void Map_AddPoint(map_t *map, point_t point);

#endif
